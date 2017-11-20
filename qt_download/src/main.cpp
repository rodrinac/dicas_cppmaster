#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QtDebug>

void writeInFile (const QString &, const QByteArray &);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkAccessManager manager;

    QObject::connect(&manager, &QNetworkAccessManager::finished, &a, &QCoreApplication::quit);

    QNetworkReply *reply = manager.get(QNetworkRequest(QUrl("http://localhost/img/cppmaster.png")));

    a.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Successo!";
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader) << "bytes";

        writeInFile("C:/Users/Jose/Desktop/cppmaster.png", reply->readAll());
    } else {
        qDebug() << "Falha!";
        qDebug() << reply->errorString();
    }

    qDebug() << "\n ------ Finalizado ------ \n\n";
}

void writeInFile (const QString &file, const QByteArray &data)
{
    QFile output(file);

    Q_ASSERT(output.open(QFile::WriteOnly | QFile::Truncate));

    output.write(data);
}
