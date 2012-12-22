#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H

#include <QWidget>
#include <QTreeView>

class PlaylistWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlaylistWidget(QWidget *parent = 0);
    
signals:
    void    selected(int, int);
public slots:
    void    selected(QModelIndex);
    void    update();

private:
    QTreeView*  m_view;
};

#endif // PLAYLISTWIDGET_H
