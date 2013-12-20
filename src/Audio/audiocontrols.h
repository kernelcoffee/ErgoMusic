#ifndef AUDIOCONTROLS_H
#define AUDIOCONTROLS_H

#include <QMediaGaplessPlaybackControl>

class AudioControls : public QMediaGaplessPlaybackControl
{
    Q_OBJECT
public:
    explicit AudioControls(QObject *parent = 0);
    
signals:
    
public slots:
};

#endif // AUDIOCONTROLS_H
