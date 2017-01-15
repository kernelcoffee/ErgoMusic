#include "singleinstance.h"
#include "common.h"

#include <QCryptographicHash>
#include <QLocalSocket>

inline QString generateInstanceName()
{
    QCryptographicHash appData( QCryptographicHash::Sha256 );
    appData.addData(APPLICATION_NAME, strlen(APPLICATION_NAME));
    appData.addData(ORGANISATION_NAME, strlen(ORGANISATION_NAME));
    appData.addData(ORGANISATION_DOMAIN, strlen(ORGANISATION_DOMAIN));

    return appData.result().toHex();
}

SingleInstance::SingleInstance(QObject *parent) :
    QObject(parent),
    m_name(generateInstanceName())
{
}

SingleInstance::~SingleInstance()
{
    unlock();
}

bool SingleInstance::check()
{
    return true;
}

bool SingleInstance::lock()
{
    QLocalServer::removeServer(m_name);
    m_server = new QLocalServer(this);

    m_server->setSocketOptions(QLocalServer::UserAccessOption);
    m_server->listen(m_name);
    connect(m_server, &QLocalServer::newConnection,
            this, &SingleInstance::onNewConnection);
    qDebug() << "New instance locked " << m_server->fullServerName();
    return true;
}

void SingleInstance::onNewConnection()
{

}

void SingleInstance::unlock()
{
    if(m_server) {
        m_server->removeServer(m_name);
        m_server->close();
        delete m_server;
    }
}
