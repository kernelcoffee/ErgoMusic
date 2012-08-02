#ifndef COREMANAGER_HPP
#define COREMANAGER_HPP

#include "Database/databasemanager.hpp"
#include "Network/networkmanager.hpp"

#include "Utilities/singleton.hpp"

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

public slots:
    void    aboutToQuit();
private:
    DatabaseManager*    m_databaseManager;
    NetworkManager*     m_networkManager;
};

#endif // COREMANAGER_HPP
