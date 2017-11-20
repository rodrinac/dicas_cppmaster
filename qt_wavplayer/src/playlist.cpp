#include "playlist.h"

PlayList::PlayList(QObject *parent) : QObject(parent)
{
//! [Carrega os sons e atribui um título para cada]
    sons["Engine"]    = new QSound(":/wav/engine-loop.wav", this);
    sons["Explosion"] = new QSound(":/wav/Explosion.wav", this);
    sons["Horn"]      = new QSound(":/wav/horn.wav", this);
    sons["Kiss"]      = new QSound(":/wav/kiss.wav", this);
    sons["Phone"]     = new QSound(":/wav/phone.wav", this);
    sons["Shooter"]   = new QSound(":/wav/shooter-action.wav", this);
//!	
}

QStringList PlayList::listar() const
{
    return sons.keys();
}

QSound *PlayList::operator [](const QString &qual)
{
    return sons[qual];
}
