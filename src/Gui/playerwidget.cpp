#include "playerwidget.h"
#include <QHBoxLayout>
#include <QTreeView>

PlayerWidget::PlayerWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout();
    QTreeView*  view     = new QTreeView();
    layout->addWidget(view);
    setLayout(layout);
}
