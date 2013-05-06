#ifndef VIEWHEADER_H
#define VIEWHEADER_H

#include <QHeaderView>

class ViewHeader : public QHeaderView
{
    Q_OBJECT
public:
    explicit ViewHeader(QWidget *parent = 0);
    ~ViewHeader();

    int visibleSectionCount() const;
signals:
    
public slots:
    
};

#endif // VIEWHEADER_H
