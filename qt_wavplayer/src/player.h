#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QScopedPointer>
#include "playlist.h"

namespace Ui {
class Player;
}

class Player : public QWidget
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = nullptr);

    ~Player();

private slots:
    void on_botaoBack_clicked();

    void on_botaoNext_clicked();

    void on_botaoPlay_clicked();

    void on_listaDeReproducao_currentRowChanged(int currentRow);

private:
    Ui::Player *ui;
    PlayList lista;

    void reproduzir(const QString &qual);
};

#endif // PLAYER_H
