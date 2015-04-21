#ifndef NOTIFICATIONCONTROLLER_H
#define NOTIFICATIONCONTROLLER_H

#include <QObject>

class NotificationController : public QObject
{
    Q_OBJECT
public:
    explicit NotificationController(QObject *parent = 0);
    ~NotificationController();

signals:

public slots:
};

#endif // NOTIFICATIONCONTROLLER_H
