#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QStringList>


class NetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *parent = 0);
    ~NetworkManager();
    void    init(QStringList&);

signals:

public slots:

};

#endif // NETWORKMANAGER_H
