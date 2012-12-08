#include "audiomanager.h"

AudioManager::AudioManager(QObject *parent) :
    QObject(parent)
{
}

AudioManager::~AudioManager()
{}

void    AudioManager::init(QStringList &arguments)
{
    Q_UNUSED(arguments);
}
