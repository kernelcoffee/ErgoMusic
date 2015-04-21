#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include <QObject>
#include <QTranslator>

class Initialization : public QObject
{
    Q_OBJECT
public:
    explicit Initialization(QObject *parent = 0);
    ~Initialization();

    void    initCores();
    void    initSettings();

signals:
    void    done();
public slots:
    void    delayedInit();
private:
    QTranslator*    _translator;


};

#endif // INITIALIZATION_H
