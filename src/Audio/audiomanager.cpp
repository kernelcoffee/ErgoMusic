#include "audiomanager.h"
#include <QMediaService>

AudioManager::AudioManager(QObject *parent) :
    QObject(parent)
{
    m_player = new QMediaPlayer;

}

AudioManager::~AudioManager()
{}

void    AudioManager::init(QStringList &arguments)
{
    Q_UNUSED(arguments);
    m_controls = m_player->service()->requestControl<QMediaGaplessPlaybackControl*>();
}

void AudioManager::setSong(AbstractPlaylist *playlist, int index)
{
    qDebug() << "set new song";
    m_player->setMedia(playlist->collection()->getTracks()->at(index)->getMedia());
    m_player->setVolume(100);
    m_player->play();
}
