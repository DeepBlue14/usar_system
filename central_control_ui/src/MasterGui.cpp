/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/central_control_ui/MasterGui.h"


MasterGui::MasterGui(QMainWindow* parent) : QMainWindow(parent)
{
    eventTimer.start(100, this);
    centralWidPtr = new CentralWidget();
    
    camGroupGuiPtr = new CamGroupGui();
    lstWidContPtr = new LstWidContainer();
    
    QScrollArea* northArea = new QScrollArea();
    northArea->setWidget(camGroupGuiPtr);
    QDockWidget* northDock = new QDockWidget();
    northDock->setWidget(northArea);
    
    QScrollArea* eastArea = new QScrollArea();
    eastArea->setWidget(lstWidContPtr);
    QDockWidget* eastDock = new QDockWidget();
    eastDock->setWidget(eastArea);
    
    connect(camGroupGuiPtr, SIGNAL(modUi(int ) ), this, SLOT(moveStuff(int ) ) );
    connect(lstWidContPtr->getOperators()->getGroup(), SIGNAL(itemSelectionChanged() ), this, SLOT(operatorWasTriggered() ) );
    
    this->addDockWidget(Qt::TopDockWidgetArea, northDock);
    this->addDockWidget(Qt::RightDockWidgetArea, eastDock);
    this->setCentralWidget(centralWidPtr);
    this->resize(1500, 850);
    this->setWindowTitle("USAR Central Control");
}


void MasterGui::timerEvent(QTimerEvent* event)
{
    ros::spinOnce();
    update();
}


void MasterGui::operatorWasTriggered()
{
    cout << "triggered @MasterGui::operatorWasTriggered(...)" << endl;
    for(size_t i = 0; i < camGroupGuiPtr->getCamVecPtr()->size(); i++)
    {
        camGroupGuiPtr->getCamVecPtr()->at(i)->unfocus();
    }
    camGroupGuiPtr->getCamVecPtr()->at(lstWidContPtr->getOperators()->getSelected())->focus();
}


void MasterGui::test_slot_2()
{
    cout << "@test_slot_2()" << endl;
}


void MasterGui::moveStuff(int index)
{
    cout << "triggered" << endl;
    lstWidContPtr->getOperators()->focus(index);
}


void MasterGui::wheelEvent(QWheelEvent* event)
{
    cout << "@MasterGui::whelEvent(...) triggered" << endl;
}


MasterGui::~MasterGui()
{
    ;
}
