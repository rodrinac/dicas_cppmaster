#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <QSound>
#include <QHash>

/**
 * Encapsula as sons presentes nos .qrc's
 * em uma playlist
 */
class PlayList : public QObject
{
    Q_OBJECT
public:
    explicit PlayList(QObject *parent = nullptr);

    QStringList listar() const;

    QSound *operator [](const QString &qual);

private:
    QHash<QString, QSound *> sons;
};

#endif // PLAYLIST_H
