#include "player.h"
#include "ui_player.h"

#include <QTimer>

Player::Player(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Player)
{
    ui->setupUi(this);    
    setFixedSize(size());

    // Método estático play() ocupa menos memória, mas possuí menor desempenho
    // !Lembre-se de colocar o .wav na mesma pasta do app compilado!
    QTimer::singleShot(1500, [this] { QSound::play("logon.wav"); });

    ui->listaDeReproducao->addItems(lista.listar());
}

Player::~Player()
{
    delete ui;
}

void Player::on_botaoBack_clicked()
{
    auto uiLista = ui->listaDeReproducao;

    if(uiLista->currentRow() != -1) {
        int atual = uiLista->currentRow();

        if(atual == 0)
            uiLista->setCurrentRow(5);
        else
            uiLista->setCurrentRow(atual - 1);
    } else
        uiLista->setCurrentRow(0);
}

void Player::on_botaoNext_clicked()
{
    auto uiLista = ui->listaDeReproducao;

    if(uiLista->currentRow() != -1) {
        int atual = uiLista->currentRow();

        if(atual == 5)
            uiLista->setCurrentRow(0);
        else
            uiLista->setCurrentRow(atual + 1);
    } else
        uiLista->setCurrentRow(0);
}

void Player::on_botaoPlay_clicked()
{
    auto uiLista = ui->listaDeReproducao;

    if(uiLista->currentRow() != -1) {
        auto qual = uiLista->currentItem()->data(Qt::DisplayRole).toString();

        reproduzir(qual);
    } else
        uiLista->setCurrentRow(0);
}

void Player::reproduzir(const QString &qual)
{
    // Usar um objeto QSound, ao invés de chamar
    // O método estático play(), ocupa mais memória,
    // mas, possuí melhor desempenho.
    // OBS.: A reprodução sempre é assíncrona, e pode ser sobreposta (mixada)
    lista[qual]->play();
}

void Player::on_listaDeReproducao_currentRowChanged(int currentRow)
{
    Q_UNUSED(currentRow)
    static bool firstTime = true;
    // A lista sempre seleciona a primeira linha/item
    // quando é preenchida
    if(firstTime) { firstTime = false; return; }

    auto uiLista = ui->listaDeReproducao;

    auto qual = uiLista->currentItem()->data(Qt::DisplayRole).toString();

    reproduzir(qual);
}
