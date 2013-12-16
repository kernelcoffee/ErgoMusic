#include "centralview.h"

CentralView::CentralView(QQuickItem *parent) :
    QQuickItem(parent)
{

}

QAbstractListModel *CentralView::model() const
{
    return CoreManager::instance()->media()->getCurrentModel();
}
