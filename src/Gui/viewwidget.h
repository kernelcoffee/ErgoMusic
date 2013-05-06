#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "Views/listview.h"


class AbstractPlaylist;

class ViewWidget : public QWidget
{
    Q_OBJECT
public:
    enum ViewType {INVALID, LIST};

    explicit ViewWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    void            selected(int, int);
private:
    void            _clean(void);
    void            _initViews(void);
    void            _selectView(AbstractPlaylist*);

    QHBoxLayout*        m_layout;

    ListView*           m_listview;
    AbstractPlaylist*   m_selectedPlaylist;
};

#endif // VIEWWIDGET_H
