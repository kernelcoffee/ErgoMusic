#ifndef SYNCENGINE_H
#define SYNCENGINE_H

#include <QSqlQuery>

/**
  * The synchronisation engine works with the remote server
  * its role is to facilitate and automatise the sync process
  */

class SyncEngine
{
public:
    SyncEngine();
    ~SyncEngine();
    void    init(QStringList&);
    void    setQuery(QSqlQuery*);
private:
    QSqlQuery*  m_query;
};

#endif // SYNCENGINE_H
