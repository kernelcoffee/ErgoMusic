#include "playlistwidget.h"
#include "playlistwidgetmodel.h"

#include "Utilities/logger.h"

#include <QGridLayout>
#include <QTreeView>

PlaylistWidget::PlaylistWidget(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout* layout = new QGridLayout(this);
    m_view     = new QTreeView();
    PlaylistWidgetModel* model = new PlaylistWidgetModel;

    layout->addWidget(m_view);
    setLayout(layout);
    m_view->setHeaderHidden(true);
    m_view->setModel(model);
    m_view->setAnimated(true);
    m_view->expandAll();
    m_view->setIndentation(15);
    m_view->setFocusPolicy(Qt::NoFocus);
    connect(m_view, SIGNAL(clicked(QModelIndex)), this, SLOT(selected(QModelIndex)));
}

void    PlaylistWidget::selected(QModelIndex index)
{
    Logger::log("Selected Item", LOG_DEBUG);
}
