#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include "Models/tablemodel.h"


class ViewWidget : public QWidget
{
    Q_OBJECT
public:
    enum Type {INVALID, TABLE};
    explicit ViewWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    void    selected(int, int);
private:
    Type    m_type;
    TableModel*    _model;
};

#endif // VIEWWIDGET_H
