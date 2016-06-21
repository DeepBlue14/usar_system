/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/robot_operator_ui/FrontCamGui.h"


FrontCamGui::FrontCamGui(bool mountPanelOnLeft, QWidget* parent) : QWidget(parent)
{
    camWidPtr = new CamWidget("/camera/rgb/image_raw");
    optionBtnPtr = new QPushButton(QIcon("src/usar_teleop/robot_operator_ui/res/wrench.png"), "");
    optionBtnPtr->setVisible(false); //!!!delete this line if you want the options button to appear!!!
    optionBtnPtr->setEnabled(false); //!!!delete this line if you want the options button to appear!!!
    strLst = new QStringList();
    *strLst << "RGB" << "IR" << "Depth map" << "Tracking" << "Off";
    radBtnWidPtr = new RadioBtnWidget("Options", strLst);
    leftPanelContainerPtr = new QWidget();
    leftPanelLay = new QGridLayout();
    leftPanelLay->addWidget(optionBtnPtr, 0, 0);
    leftPanelLay->addWidget(radBtnWidPtr, 1, 0);
    
    outerLayout = new QGridLayout();
    if(mountPanelOnLeft)
    {
        outerLayout->addLayout(leftPanelLay, 0, 0, Qt::AlignTop | Qt::AlignLeft);
        outerLayout->addWidget(camWidPtr, 0, 1, 10, 10);
    }
    else
    {
        outerLayout->addLayout(leftPanelLay, 0, 1, Qt::AlignTop | Qt::AlignLeft);
        outerLayout->addWidget(camWidPtr, 0, 0, 10, 10);
    }
    
    //this->setStyleSheet("QWidget { background-color: yellow}");
    this->setLayout(outerLayout);
}


void FrontCamGui::loadContent()
{
    ;
}


void FrontCamGui::unloadContent()
{
    ;
}


void FrontCamGui::setCamWidPtr(CamWidget* camWidPtr)
{
    this->camWidPtr = camWidPtr;
}


CamWidget* FrontCamGui::getCamWidPtr() const
{
    return camWidPtr;
}


char* FrontCamGui::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    return str;
}


FrontCamGui::~FrontCamGui()
{
    delete camWidPtr;
    delete optionBtnPtr;
    delete strLst;
    delete radBtnWidPtr;
    delete leftPanelContainerPtr;
    delete leftPanelLay;
    delete outerLayout;
}
