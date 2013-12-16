#ifndef CENTRALVIEW_H
#define CENTRALVIEW_H

#include <QQuickItem>
#include <coremanager.h>

class CentralView : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QAbstractListModel* model READ model NOTIFY modelChanged)
public:
    explicit CentralView(QQuickItem *parent = 0);
    
    QAbstractListModel *model() const;
signals:
    void    modelChanged();
public slots:

};

#endif // CENTRALVIEW_H
