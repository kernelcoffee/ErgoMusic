#include "library.h"
//#include "Gui/viewwidget.h"

Library::Library(QObject *parent) :
    AbstractPlaylist(parent)
{
}

Library::Library(QList<Track *> *list, QObject *parent) :
    AbstractPlaylist(parent)
{
//    m_viewType = ViewWidget::INVALID;
    m_list = list;
}
