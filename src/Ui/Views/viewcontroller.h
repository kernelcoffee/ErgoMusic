#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>
#include "Ui/uicommon.h"
#include "Ui/Media/Models/trackmodel.h"
#include "Model/tracksortmodel.h"

class ViewController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int selectedIndex READ selectedIndex WRITE setSelectedIndex NOTIFY selectedIndexChanged)
    Q_PROPERTY(ModelType selectedType READ selectedType WRITE setSelectedType NOTIFY selectedTypeChanged)
    Q_PROPERTY(TrackModel *trackModel READ trackModel NOTIFY trackModelChanged)
    Q_PROPERTY(TrackSortModel *trackSortModel READ trackSortModel WRITE setTrackSortModel NOTIFY trackSortModelChanged)

public:
    explicit ViewController(QObject *parent = 0);
    ~ViewController();

    Q_INVOKABLE void undo();
    Q_INVOKABLE void redo();

    int selectedIndex() const;
    ModelType selectedType() const;
    TrackModel *trackModel() const;
    TrackSortModel *trackSortModel() const;

signals:
    void selectedIndexChanged(int index);
    void selectedTypeChanged(ModelType type);
    void trackModelChanged(TrackModel *arg);
    void trackSortModelChanged(TrackSortModel *trackSortModel);

public slots:
    void setSelectedIndex(int index);
    void setSelectedType(ModelType type);

    Q_INVOKABLE void setTrackModel(ModelType type, int index);
    void setTrackSortModel(TrackSortModel *trackSortModel);

private:
    int m_selectedIndex;
    ModelType m_selectedType;
    TrackModel *m_trackModel;
    TrackSortModel *m_trackSortModel;
};

#endif // VIEWCONTROLLER_H
