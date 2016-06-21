/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/robot_operator_ui/GunCamGui.h"


GunCamGui::GunCamGui(bool mountPanelOnLeft, QWidget* parent) : QWidget(parent)
{
    camWidPtr = new CamWidget("/trajectory_rgbd/scope");
    ammoCountLblPtr = new QLabel("<b>3</b> rounds");
    strLst = new QStringList();
    *strLst << "RGB" << "Tracking" << "Autonomous" << "Off";
    radBtnWidPtr = new RadioBtnWidget("Options", strLst);
    leftPanelContainerPtr = new QWidget();
    
    leftPanelLay = new QGridLayout();
    leftPanelLay->addWidget(ammoCountLblPtr, 0, 0);
    leftPanelLay->addWidget(radBtnWidPtr, 1, 0);
    
    leftPanelLayWid = new QWidget();
    leftPanelLayWid->setLayout(leftPanelLay);
    
    outerLayout = new QGridLayout();

    mountPanelLeft(mountPanelOnLeft);
    
    this->setLayout(outerLayout);
}


void GunCamGui::loadContent()
{
    ;
}


void GunCamGui::unloadContent()
{
    outerLayout->removeWidget(leftPanelLayWid);
    outerLayout->removeWidget(camWidPtr);
    leftPanelLayWid->setVisible(false);
    leftPanelLayWid->setEnabled(false);
    camWidPtr->setVisible(false);
    camWidPtr->setEnabled(false);
}


void GunCamGui::mountPanelLeft(bool mountPanelOnLeft)
{
    unloadContent();

    if(mountPanelOnLeft)
    {
        outerLayout->addWidget(leftPanelLayWid, 0, 0, Qt::AlignTop | Qt::AlignLeft);
        outerLayout->addWidget(camWidPtr, 0, 1, 10, 10);
    }
    else
    {
        outerLayout->addWidget(leftPanelLayWid, 1, 11, Qt::AlignTop | Qt::AlignRight);
        outerLayout->addWidget(camWidPtr, 0, 0, 10, 10);
    }
    
    leftPanelLayWid->setVisible(true);
    leftPanelLayWid->setEnabled(true);
    camWidPtr->setVisible(true);
    camWidPtr->setEnabled(true);
}


void GunCamGui::setCamWidPtr(CamWidget* camWidPtr)
{
    this->camWidPtr = camWidPtr;
}


CamWidget* GunCamGui::getCamWidPtr() const
{
    return camWidPtr;
}


char* GunCamGui::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    return str;
}


GunCamGui::~GunCamGui()
{
    delete camWidPtr;
    delete ammoCountLblPtr;
    delete strLst;
    delete radBtnWidPtr;
    delete leftPanelContainerPtr;
    delete leftPanelLay;
    delete leftPanelLayWid;
    delete outerLayout;
}
