#include "playerwidget.h"
#include <QHBoxLayout>
#include <QTreeView>

PlayerWidget::PlayerWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout();
    setLayout(layout);

    setMaximumHeight(70);
}
