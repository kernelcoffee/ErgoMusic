#include "sidebarwidget.h"
#include "Models/sidebarwidgetmodel.h"

#include "Utilities/logger.h"

#include <QGridLayout>
#include <QTreeView>

SidebarWidget::SidebarWidget(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout* layout = new QGridLayout(this);
    m_view     = new QTreeView();
    SidebarWidgetModel* model = new SidebarWidgetModel;

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

void    SidebarWidget::selected(QModelIndex index)
{
    SidebarWidgetItem* data = static_cast<SidebarWidgetItem*>(index.internalPointer());
    selected(data->getType(), data->getIndex());
}

void    SidebarWidget::update()
{

}
