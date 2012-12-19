#include "viewwidget.h"
#include <QHBoxLayout>
#include <QTableView>

ViewWidget::ViewWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout();
    QTableView*  view = new QTableView();
    layout->addWidget(view);
    setLayout(layout);

    view->setFocusPolicy(Qt::NoFocus);
}
