#include "viewcontroller.h"
#include "coremanager.h"

ViewController::ViewController(QObject *parent) :
    QObject(parent)
  , m_trackModel(new TrackModel)
{

}

ViewController::~ViewController()
{

}

void ViewController::undo()
{
    CoreManager::instance()->undo();
}

void ViewController::redo()
{
    CoreManager::instance()->redo();
}

int ViewController::selectedIndex() const
{
    return m_selectedIndex;
}

ModelType ViewController::selectedType() const
{
    return m_selectedType;
}

TrackModel *ViewController::trackModel() const
{
    return m_trackModel;
}

void ViewController::setSelectedIndex(int index)
{
    if (m_selectedIndex == index)
        return;

    m_selectedIndex = index;
    emit selectedIndexChanged(index);
}

void ViewController::setSelectedType(ModelType type)
{
    if (m_selectedType == type)
        return;

    m_selectedType = type;
    emit selectedTypeChanged(type);
}

void ViewController::setTrackModel(ModelType type, int index)
{
    setSelectedIndex(index);
    setSelectedType(type);
    switch (type) {
    case ModelType::WATCHPLAYLIST:
        m_trackModel->setModel(CoreManager::instance()->media()->watchPlaylists()->at(index));
        break;
    default:
        break;
    }
    emit trackModelChanged(m_trackModel);
}
