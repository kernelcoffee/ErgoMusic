#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <QObject>
#include <QStringList>
#include <QMediaPlayer>
#include <QMediaGaplessPlaybackControl>
#include "Utilities/Abstract/abstractplaylist.h"
#include "audiocontrols.h"

class AudioManager : public QObject
{
    Q_OBJECT
public:
    explicit AudioManager(QObject *parent = 0);
    ~AudioManager();
    void    init(QStringList&);
signals:
    
public slots:
    void    setSong(AbstractPlaylist*, int);
private:
    QMediaGaplessPlaybackControl*   m_controls;
    QMediaPlayer*                   m_player;
};

#endif // AUDIOMANAGER_H
