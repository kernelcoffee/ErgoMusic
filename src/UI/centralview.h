#ifndef CENTRALVIEW_H
#define CENTRALVIEW_H

#include <QQuickItem>
#include <coremanager.h>
#include "Models/playlistmodel.h"

class CentralView : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(PlaylistModel* model READ model NOTIFY modelChanged)
    Q_PROPERTY(QString state READ state WRITE setState NOTIFY stateChanged)
public:
    explicit CentralView(QQuickItem *parent = 0);
    
    Q_INVOKABLE void    setModel(int, int);

    PlaylistModel*      model() const;
    QString             state() const;
signals:
    void    modelChanged();
    void    stateChanged();
public slots:

private:
    QString             m_state;
    MediaManager        *m_media;
};

#endif // CENTRALVIEW_H
