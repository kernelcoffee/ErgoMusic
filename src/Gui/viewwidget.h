#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include <QHBoxLayout>

class AbstractPlaylist;

class ViewWidget : public QWidget
{
    Q_OBJECT
public:
    enum ViewType {INVALID, LIST};

    explicit ViewWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    void    selected(int, int);
private:
    void            _selectView(AbstractPlaylist*);

    QHBoxLayout*    m_layout;
};

#endif // VIEWWIDGET_H
