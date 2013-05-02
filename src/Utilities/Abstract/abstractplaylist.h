#ifndef ABSTRACTPLAYLIST_H
#define ABSTRACTPLAYLIST_H

#include <QObject>
#include "Gui/viewwidget.h"

class Track;
class ViewWidget;

class AbstractPlaylist : public QObject
{
    Q_OBJECT
public:
    enum Type {INVALID, LIBRARY, WATCHPLAYLIST, PLAYLIST, DPLAYLIST};

    virtual ~AbstractPlaylist();

    virtual void                setViewType(ViewWidget::ViewType);

    virtual Type                getType(void) const;
    virtual QList<Track*>*      getList(void) const;
    virtual ViewWidget::ViewType    getViewType(void) const;
protected:
    AbstractPlaylist();
    AbstractPlaylist(QObject *parent = 0);

    QList<Track*>*      m_list;
    Type                m_type;
    ViewWidget::ViewType    m_viewType;
signals:
    void    updated();
};

#endif // ABSTRACTPLAYLIST_H
