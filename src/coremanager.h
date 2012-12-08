#ifndef COREMANAGER_H
#define COREMANAGER_H

#include "Database/databasemanager.h"
#include "Network/networkmanager.h"
#include "Audio/audiomanager.h"

#include "Utilities/singleton.h"

class CoreManager : public QObject, public Singleton<CoreManager>
{
    friend class Singleton<CoreManager>;

    Q_OBJECT
public:
    CoreManager();
    ~CoreManager();
    void    initManagers(QStringList&);
    void    deleteManagers();

    DatabaseManager*    database() const;
    NetworkManager*     network() const;
    AudioManager*       audio() const;

public slots:
    void    aboutToQuit();
private:
    DatabaseManager*    m_databaseManager;
    NetworkManager*     m_networkManager;
    AudioManager*       m_audioManager;
};

#endif // COREMANAGER_H
