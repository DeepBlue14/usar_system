/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/central_control_ui/MapGui.h"

MapGui::MapGui(const char* fileName, QWidget* parent) : QWidget(parent)
{
    mapWidPtr = new MapWidget(-1, fileName);
    mapDatWidPtr = new MapDataWidget();
    
    outerLayout = new QGridLayout();
    outerLayout->addWidget(mapWidPtr, 0, 0);
    outerLayout->addWidget(mapDatWidPtr, 1, 0);
    
    this->setLayout(outerLayout);
}


MapWidget* MapGui::getMapWidget() const
{
    return mapWidPtr;
}


char* MapGui::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


MapGui::~MapGui()
{
    ;
}