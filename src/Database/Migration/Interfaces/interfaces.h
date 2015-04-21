#ifndef INTERFACES_H
#define INTERFACES_H

#include <QObject>

class Interfaces : public QObject
{
    Q_OBJECT
public:
    explicit Interfaces(QObject *parent = 0);
    ~Interfaces();

signals:

public slots:
};

#endif // INTERFACES_H
