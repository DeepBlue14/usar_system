/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */


#include "../include/operator_ui/MasterGui.h"


MasterGui::MasterGui(QMainWindow* parent) : QMainWindow(parent)
{
    eventTimer.start(100, this);
    
    gunCamGuiPtr = new GunCamGui();
    joyUiBridge = new JoyUiBridge();
    
    connect(joyUiBridge, SIGNAL(swapTopic(int ) ), gunCamGuiPtr, SLOT(handleSwapTopicSlot(int ) ) );
    connect(joyUiBridge, SIGNAL(armSys(bool ) ), gunCamGuiPtr, SLOT(handleArmSysSlot(bool ) ) );
    
    //this->setStyleSheet("QWidget { background-color: blue}");
    this->setCentralWidget(gunCamGuiPtr);
    this->resize(925, 700);
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
    delete gunCamGuiPtr;
}
