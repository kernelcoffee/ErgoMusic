#include "networkmanager.h"

NetworkManager::NetworkManager(QObject *parent) :
    QObject(parent)
{
}

NetworkManager::~NetworkManager()
{}

void    NetworkManager::init(QStringList &arguments)
{
    Q_UNUSED(arguments);
}
