#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>
#include "Ui/uicommon.h"
#include "Ui/Media/Models/trackmodel.h"

class ViewController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int selectedIndex READ selectedIndex WRITE setSelectedIndex NOTIFY selectedIndexChanged)
    Q_PROPERTY(ModelType selectedType READ selectedType WRITE setSelectedType NOTIFY selectedTypeChanged)
    Q_PROPERTY(TrackModel* trackModel READ trackModel NOTIFY trackModelChanged)

public:
    explicit ViewController(QObject *parent = 0);
    ~ViewController();


    int         selectedIndex() const;
    ModelType   selectedType() const;
    TrackModel* trackModel() const;

signals:
    void selectedIndexChanged(int index);
    void selectedTypeChanged(ModelType type);
    void trackModelChanged(TrackModel* arg);

public slots:
    void setSelectedIndex(int index);
    void setSelectedType(ModelType type);

    Q_INVOKABLE void    setTrackModel(ModelType type, int index);

private:
    int         m_selectedIndex;
    ModelType   m_selectedType;
    TrackModel* m_trackModel;
};

#endif // VIEWCONTROLLER_H
