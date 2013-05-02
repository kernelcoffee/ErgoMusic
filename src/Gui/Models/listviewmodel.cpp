#include "listviewmodel.h"

ListViewModel::ListViewModel(QObject *parent) :
    TreeModel(parent)
{
}

ListViewModel::~ListViewModel()
{
}

void ListViewModel::setPlaylist(AbstractPlaylist *playlist)
{
    m_playlist = playlist;
}

void ListViewModel::setupModelData()
{
}
