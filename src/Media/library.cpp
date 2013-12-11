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

void Library::insert(int, const Track *)
{

}

void Library::append(const Track *)
{

}

void Library::remove(int)
{

}

QObject *Library::get(int)
{

}

void Library::setProperty(int index, const QString &property, const QVariant &value)
{

}
