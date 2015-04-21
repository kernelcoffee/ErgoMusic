#ifndef WATCHPLAYLIST_H
#define WATCHPLAYLIST_H

#include "Media/Abstracts/abstractplaylist.h"
#include <QFileSystemWatcher>

class WatchPlaylist : public AbstractPlaylist
{
    Q_OBJECT
public:
    enum Status {
        Idle,
        Busy
    };

    explicit WatchPlaylist(QString path, QObject *parent = 0);
    explicit WatchPlaylist(int id, QString name, QString path, QObject *parent = 0);
    ~WatchPlaylist();

    QString path() const;
    Status  status() const;

    void    clear();

signals:
    void    statusChanged(Status status);

    void    requestRefresh();
    void    refreshed();
    void    updated();
    void    cleared();

public slots:
    void    refresh();
    void    setStatus(Status status);

private:
    void    _update();
    void    _disabled();

    QString             m_path;
    QFileSystemWatcher  m_watchfolder;
    Status              m_status;
};

#endif // WATCHPLAYLIST_H
