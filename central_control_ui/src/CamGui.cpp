/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/central_control_ui/CamGui.h"

CamGui::CamGui(const char* fileName, QWidget* parent) : QWidget(parent)
{
    camWidPtr = new CamWidget(-1, fileName);
    agentDatWidPtr = new AgentDataWidget();
    
    outerLayout = new QGridLayout();
    outerLayout->addWidget(camWidPtr, 0, 0);
    outerLayout->addWidget(agentDatWidPtr, 1, 0);
    
    this->setLayout(outerLayout);
}


CamWidget* CamGui::getCamWidget() const
{
    return camWidPtr;
}


char* CamGui::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


CamGui::~CamGui()
{
    ;
}