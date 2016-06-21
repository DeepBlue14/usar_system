/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */


#include "../include/robot_operator_ui/MasterGui.h"


MasterGui::MasterGui(QMainWindow* parent) : QMainWindow(parent)
{
    eventTimer.start(100, this);
    
    centralWidgetPtr = new CentralWidget();
    
    //this->setStyleSheet("QWidget { background-color: blue}");
    this->setCentralWidget(centralWidgetPtr);
    this->resize(1600, 950);
}


void MasterGui::timerEvent(QTimerEvent* event)
{
    ros::spinOnce();
    update();
}


char* MasterGui::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


MasterGui::~MasterGui()
{
    delete centralWidgetPtr;
}
