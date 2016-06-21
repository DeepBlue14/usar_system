/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/robot_operator_ui/MapGui.h"


MapGui::MapGui(bool mountPanelOnLeft, QWidget* parent) : QWidget(parent)
{
    camWidPtr = new MapWidget("src/usar_teleop/robot_operator_ui/res/3rdfloor_5cm.png");
    optionBtnPtr = new QPushButton(QIcon("src/usar_teleop/robot_operator_ui/res/config.png"), "");
    opConfigGuiPtr = new OpConfigGui();
    status = new QLabel();
    robotStat = new QLabel();
    robotLbl = new QLabel();
    gunStat = new QLabel();
    gunLbl = new QLabel();
    comdrStat = new QLabel();
    comdrLbl = new QLabel();
    status->setTextFormat(Qt::RichText);
    robotStat->setTextFormat(Qt::RichText);
    gunStat->setTextFormat(Qt::RichText);
    comdrStat->setTextFormat(Qt::RichText);
    status->setText("<b>Status</b>");
    robotStat->setPixmap(QPixmap("src/usar_teleop/robot_operator_ui/res/go2.png") );
    robotLbl->setText("Robot");
    gunStat->setPixmap(QPixmap("src/usar_teleop/robot_operator_ui/res/disabled2.png") );
    gunLbl->setText("Nerf");
    comdrStat->setPixmap(QPixmap("src/usar_teleop/robot_operator_ui/res/warning2.png") );
    comdrLbl->setText("Comdr");
    strLst = new QStringList();
    *strLst << "Overview" << "Zoom" << "1st person" << "Off";
    radBtnWidPtr = new RadioBtnWidget("Options", strLst);
    leftPanelContainerPtr = new QWidget();
    leftPanelLay = new QGridLayout();
    
    statusLay = new QGridLayout();
    leftPanelLay->addWidget(optionBtnPtr, 0, 0);
    leftPanelLay->addWidget(radBtnWidPtr, 1, 0);
    leftPanelLay->addWidget(status, 2, 0);
    
    statusLay->addWidget(robotStat, 1, 0);
    statusLay->addWidget(robotLbl, 1, 1);
    statusLay->addWidget(gunStat, 2, 0);
    statusLay->addWidget(gunLbl, 2, 1);
    statusLay->addWidget(comdrStat, 3, 0);
    statusLay->addWidget(comdrLbl, 3, 1);
    
    leftPanelLay->addLayout(statusLay, 3, 0);
    
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
    
    connect(optionBtnPtr, SIGNAL(released() ), this, SLOT(handleOptionBtnPtrSlot() ) );
    
    //this->setStyleSheet("QWidget { background-color: yellow}");
    this->setLayout(outerLayout);
    //this->resize(200, 200);
}


void MapGui::handleOptionBtnPtrSlot()
{
    opConfigGuiPtr->show();
}


void MapGui::loadContent()
{
    ;
}


void MapGui::unloadContent()
{
    ;
}


void MapGui::setCamWidPtr(MapWidget* camWidPtr)
{
    this->camWidPtr = camWidPtr;
}


MapWidget* MapGui::getCamWidPtr() const
{
    return camWidPtr;
}


char* MapGui::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    return str;
}


MapGui::~MapGui()
{
    delete camWidPtr;
    delete optionBtnPtr;
    delete status;
    delete robotStat;
    delete gunStat;
    delete comdrStat;
    delete strLst;
    delete radBtnWidPtr;
    delete leftPanelLay;
    delete leftPanelContainerPtr;
    delete outerLayout;
}
