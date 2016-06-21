/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/robot_operator_ui/CentralWidget.h"


CentralWidget::CentralWidget(QWidget* parent) : QWidget(parent)
{
    vertSplitter = new QSplitter();
    horizSplitter = new QSplitter();
    leftCamGuiPtr = new MapGui();
    rightGunGuiPtr = new GunCamGui(/*false*/);
    rightGunGuiPtr2 = new FrontCamGui();
    tabWidgetPtr = new QTabWidget();
    
    outerLayout = new QGridLayout();

    isTabMode = true;
    mapIsHidden = false;
    
    //test dyn ui changes
    
    //loadTabMode();
    //unloadTabMode();
    //loadTabMode();
    
    //loadWinMode();
    //unloadWinMode();
    //loadWinMode();

    //loadTabMode();
    //unloadTabMode();
    loadWinMode();

    //loadWinMode();
    //unloadWinMode();
    //loadTabMode();

    this->setLayout(outerLayout);
}


void CentralWidget::loadTabMode()
{
    rightGunGuiPtr->mountPanelLeft(true);

    tabWidgetPtr->addTab(rightGunGuiPtr2, "Robot");
    tabWidgetPtr->addTab(rightGunGuiPtr, "Gun");
    vertSplitter->setOrientation(Qt::Vertical);
    //tabWidgetPtr->addTab(rightGunGuiPtr2, "Robot");
    //tabWidgetPtr->addTab(rightGunGuiPtr, "Gun");
    vertSplitter->addWidget(leftCamGuiPtr);
    vertSplitter->addWidget(tabWidgetPtr);
    
    tabWidgetPtr->setCurrentIndex(1);
    
    outerLayout->addWidget(vertSplitter, 0, 0);
    vertSplitter->setVisible(true);
    vertSplitter->setEnabled(true);
    leftCamGuiPtr->setVisible(true);
    leftCamGuiPtr->setEnabled(true);
}


void CentralWidget::unloadTabMode()
{
    tabWidgetPtr->removeTab(0);
    tabWidgetPtr->removeTab(1);
    outerLayout->removeWidget(vertSplitter);
    vertSplitter->setVisible(false);
    vertSplitter->setEnabled(false);
}


void CentralWidget::loadWinMode()
{
    rightGunGuiPtr->mountPanelLeft(false);

    //tabWidgetPtr->addTab(rightGunGuiPtr2, "Robot");
    outerLayout->addWidget(leftCamGuiPtr, 0, 0);
    horizSplitter->setOrientation(Qt::Horizontal);
    horizSplitter->addWidget(rightGunGuiPtr2/*tabWidgetPtr*/);
    horizSplitter->addWidget(rightGunGuiPtr);
    outerLayout->addWidget(horizSplitter);
    //outerLayout->addWidget(tabWidgetPtr, 1, 0);
    //outerLayout->addWidget(rightGunGuiPtr, 1, 1);
    horizSplitter->setVisible(true);
    horizSplitter->setEnabled(true);
    rightGunGuiPtr->setVisible(true); //TODO: why was this line nessissary?
    rightGunGuiPtr->setEnabled(true);
    leftCamGuiPtr->setVisible(true); //TODO: why was this line nessissary?
    leftCamGuiPtr->setEnabled(true);
    rightGunGuiPtr2->setVisible(true); //TODO: why was this line nessissary?
    rightGunGuiPtr2->setEnabled(true);


}


void CentralWidget::unloadWinMode()
{
    outerLayout->removeWidget(leftCamGuiPtr);
    outerLayout->removeWidget(horizSplitter);
    horizSplitter->setVisible(false);
    horizSplitter->setEnabled(false);
    leftCamGuiPtr->setVisible(false);
    leftCamGuiPtr->setEnabled(false);
}


void CentralWidget::keyPressEvent(QKeyEvent* event)
{
    switch(event->key() )
    {
        case Qt::Key_D:
            if(isTabMode)
            {
                cout << "loading win mode" << endl;
                unloadTabMode();
                loadWinMode();
                isTabMode = false;
            }
            else
            {
                cout << "loading tab mode" << endl;
                unloadWinMode();
                loadTabMode();
                isTabMode = true;
            }
            break;
        case Qt::Key_K:
            if(mapIsHidden)
            {
                leftCamGuiPtr->setEnabled(true);
                leftCamGuiPtr->setVisible(true);
                mapIsHidden = false;
            }
            else
            {
                leftCamGuiPtr->setEnabled(false);
                leftCamGuiPtr->setVisible(false);
                mapIsHidden = true;
            }
    }
}


char* CentralWidget::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


CentralWidget::~CentralWidget()
{
    delete vertSplitter;
    delete horizSplitter;
    delete leftCamGuiPtr;
    delete rightGunGuiPtr;
    delete rightGunGuiPtr2;
    delete tabWidgetPtr;
    delete outerLayout;
}
