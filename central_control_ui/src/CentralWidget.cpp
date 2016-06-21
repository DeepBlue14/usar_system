/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/central_control_ui/CentralWidget.h"


CentralWidget::CentralWidget(QWidget* parent) : QWidget(parent)
{
    currentMode = CentralWidget::TWIN;
    camGuiPtr = new CamGui("src/usar_teleop/central_control_ui/res/place_holder.jpg");
    mapGuiPtr = new MapGui("src/usar_teleop/central_control_ui/res/world_fit_noalpha.png");
    //mapGuiPtr->getMapWidget()->addColoredBorder();
    mapGuiPtr->getMapWidget()->addBorder();
    
    outerLayout = new QGridLayout();
    loadTwinMode();
    //loadMapMode();
    
    connect(mapGuiPtr->getMapWidget()->getLabel(), SIGNAL(swapUiMode() ), this, SLOT(callback() ) );
    
    this->setLayout(outerLayout);
}


void CentralWidget::callback()
{
    switch(currentMode)
    {
        case CentralWidget::TWIN:
            unloadTwinMode();
            loadMapMode();
            currentMode = CentralWidget::MAP;
            break;
        case CentralWidget::MAP:
            unloadMapMode();
            loadTwinMode();
            currentMode = CentralWidget::TWIN;
            break;
        default:
            cerr << "ERROR @ CentralWidget::callback()" << endl;
    }
    
    
}


void CentralWidget::loadTwinMode()
{
    camGuiPtr->setVisible(true);
    camGuiPtr->setEnabled(true);
    mapGuiPtr->setVisible(true);
    mapGuiPtr->setEnabled(true);
    mapGuiPtr->getMapWidget()->setMap("src/usar_teleop/central_control_ui/res/world_fit.png", true);
    
    outerLayout->addWidget(camGuiPtr, 0, 0);
    outerLayout->addWidget(mapGuiPtr, 0, 1);
}


void CentralWidget::unloadTwinMode()
{
    outerLayout->removeWidget(camGuiPtr);
    outerLayout->removeWidget(mapGuiPtr);
    camGuiPtr->setVisible(false);
    camGuiPtr->setEnabled(false);
    mapGuiPtr->setVisible(false);
    mapGuiPtr->setEnabled(false);
}


void CentralWidget::loadMapMode()
{
    mapGuiPtr->setVisible(true);
    mapGuiPtr->setEnabled(true);
    mapGuiPtr->getMapWidget()->setMap("src/usar_teleop/central_control_ui/res/3rdfloor_5cm.png", false);
    outerLayout->addWidget(mapGuiPtr, 0, 0, Qt::AlignCenter); //TODO: also expand map
}


void CentralWidget::unloadMapMode()
{
    outerLayout->removeWidget(mapGuiPtr);
    mapGuiPtr->setVisible(false);
    mapGuiPtr->setEnabled(false);
}


char* CentralWidget::toString()
{
    char* str = const_cast<char*>("***METHOD STUB");
    
    return str;
}


CentralWidget::~CentralWidget()
{
    ;
}
