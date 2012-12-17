#include "playlistwidget.h"
#include "playlistwidgetmodel.h"
#include <QGridLayout>
#include <QTreeView>

PlaylistWidget::PlaylistWidget(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout* layout = new QGridLayout(this);
    m_view     = new QTreeView();

    layout->addWidget(m_view);
    setLayout(layout);
    m_view->setHeaderHidden(true);
}
