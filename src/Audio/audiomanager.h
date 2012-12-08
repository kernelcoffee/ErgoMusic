#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <QObject>
#include <QStringList>

class AudioManager : public QObject
{
    Q_OBJECT
public:
    explicit AudioManager(QObject *parent = 0);
    ~AudioManager();
    void    init(QStringList&);
signals:
    
public slots:

private:
};

#endif // AUDIOMANAGER_H
