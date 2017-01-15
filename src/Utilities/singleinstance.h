#ifndef SINGLEINSTANCE_H
#define SINGLEINSTANCE_H

#include <QObject>
#include <QLocalServer>

class SingleInstance : public QObject
{
    Q_OBJECT
public:
    explicit SingleInstance(QObject *parent = 0);
    ~SingleInstance();

    static bool check();
    static void sendData(int argc, char *argv[]);

    bool lock();
signals:

public slots:
    void onNewConnection();
    void unlock();

private:
    QString m_name;
    QLocalServer *m_server;
};

#endif // SINGLEINSTANCE_H
