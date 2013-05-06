#include "viewheader.h"

ViewHeader::ViewHeader(QWidget *parent) :
       QHeaderView(Qt::Horizontal, parent )
{
    setMinimumSectionSize( 60 );
    setDefaultAlignment( Qt::AlignLeft );
    setStretchLastSection( true );
}

ViewHeader::~ViewHeader()
{}

int ViewHeader::visibleSectionCount() const
{
    return count() - hiddenSectionCount();
}
