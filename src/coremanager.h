#ifndef COREMANAGER_H
#define COREMANAGER_H

#include "Database/databasemanager.h"
#include "Network/networkmanager.h"
#include "Audio/audiomanager.h"
#include "Media/mediamanager.h"

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
    MediaManager*       media() const;
public slots:
    void    aboutToQuit();
private:
    DatabaseManager*    m_databaseManager;
    NetworkManager*     m_networkManager;
    AudioManager*       m_audioManager;
    MediaManager*       m_mediaManager;
};

#endif // COREMANAGER_H
