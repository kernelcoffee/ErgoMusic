#include "viewwidget.h"
#include <QHBoxLayout>
#include <QTreeView>

ViewWidget::ViewWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout();
    QTreeView*  view = new QTreeView();
    layout->addWidget(view);
    setLayout(layout);
}
