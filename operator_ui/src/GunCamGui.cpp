/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/operator_ui/GunCamGui.h"


GunCamGui::GunCamGui(bool mountPanelOnLeft, QWidget* parent) : QWidget(parent)
{
    currTopicIndex = 1;
    camWidPtr = new CamWidget("/trajectory_rgbd/scope");
    //ammoCountLblPtr = new QLabel("<b>3</b> rounds");
    strLst = new QStringList();
    *strLst << "RGB" << "Tracking" << "Autonomous" << "Off";
    

    wid = new QWidget();
    lay = new QGridLayout();
    wid->setLayout(lay);
    
    mapLbl = new QLabel();
    mapLbl->setPixmap(QPixmap("src/usar_teleop/operator_ui/res/midget_map2_opacity_50.png") );
    
    hriMap = new HriMap();
    //QWidget* wid_3 = new QWidget();
    //QGridLayout* lay_3 = new QGridLayout();
    //wid_3->setLayout(lay_3);
    //lay_3->addWidget(map, 0, 0, Qt::AlignCenter);
    //http://stackoverflow.com/questions/3894737/qt4-how-to-draw-inside-a-widget
    
    
    QLabel* robotLbl = new QLabel();
    gunLbl = new QLabel();
    QLabel* ccLbl = new QLabel();
    robotLbl->setTextFormat(Qt::RichText);
    robotLbl->setPixmap(QPixmap("src/usar_teleop/operator_ui/res/robot2_disabled.png") );
    gunLbl->setPixmap(QPixmap("src/usar_teleop/operator_ui/res/missile_3_disabled.png") );
    ccLbl->setPixmap(QPixmap("src/usar_teleop/operator_ui/res/central_control_disabled.png") );
    lay->addWidget(robotLbl, 0, 0, Qt::AlignBottom | Qt::AlignCenter);
    lay->addWidget(gunLbl, 0, 1, Qt::AlignBottom | Qt::AlignCenter);
    lay->addWidget(ccLbl, 0, 2, Qt::AlignBottom | Qt::AlignCenter);
    //lay->addWidget(new QLabel("<font size=\"5\" color=\"red\"><b>Agent<b></font>") , 1, 0, Qt::AlignBottom | Qt::AlignCenter);
    //lay->addWidget(new QLabel("<font size=\"5\" color=\"purple\"><b>3 <b></font><font size=\"5\" color=\"red\"><b>Gun<b></font>") , 1, 1, Qt::AlignBottom | Qt::AlignCenter);
    //lay->addWidget(new QLabel("<font size=\"5\" color=\"red\"><b>CRL<b></font>") , 1, 2, Qt::AlignBottom | Qt::AlignCenter);

    QWidget* wid_2 = new QWidget();
    QGridLayout* lay_2 = new QGridLayout();
    wid_2->setLayout(lay_2);

    topicWidVec = new QVector<CustomLabel*>();
    topicWidVec->push_back(new CustomLabel("RGB", "/camera/rgb/image_rect_color") );
    topicWidVec->push_back(new CustomLabel("Scope", "/trajectory_rgbd/scope") );
    topicWidVec->push_back(new CustomLabel("Track", "/target_aquisition/rgb/image_with_face") );
    topicWidVec->push_back(new CustomLabel("IR", "/camera/ir/image") );
    
    
    for(size_t i = 0; i < topicWidVec->size(); i++)
    {
        topicWidVec->at(i)->setIsSelected(false);
        topicWidVec->at(i)->setIsActivated(false);
    }
    topicWidVec->at(1)->setIsSelected(true);
    topicWidVec->at(1)->setIsActivated(true);
    
    lay_2->addWidget(topicWidVec->at(0), 0, 0, Qt::AlignLeft | Qt::AlignCenter);
    lay_2->addWidget(topicWidVec->at(1), 1, 0, Qt::AlignLeft | Qt::AlignCenter);
    lay_2->addWidget(topicWidVec->at(2), 2, 0, Qt::AlignLeft | Qt::AlignCenter);
    lay_2->addWidget(topicWidVec->at(3), 3, 0, Qt::AlignLeft | Qt::AlignCenter);
    
    outerLayout = new QGridLayout();
    outerLayout->addWidget(camWidPtr, 0, 0);
    //outerLayout->addWidget(mapLbl, 0, 0, Qt::AlignTop | Qt::AlignCenter);
    outerLayout->addWidget(hriMap, 0, 0, Qt::AlignBottom | Qt::AlignLeft); //FIXME: why isn't this appearing???
    outerLayout->addWidget(wid, 0, 0, Qt::AlignBottom | Qt::AlignCenter);
    outerLayout->addWidget(wid_2, 0, 0, Qt::AlignLeft | Qt::AlignCenter);
    
    this->setLayout(outerLayout);
}


void GunCamGui::handleSwapTopicSlot(int buttonState)
{
    cout << "@GunCamGui::handleSwapTopicSlot(); buttonstate: " << buttonState << endl;

    switch(buttonState)
    {
        case GunCamGui::UP:
            if(currTopicIndex > 0)
            {
                topicWidVec->at(currTopicIndex-1)->setIsSelected(true);
                topicWidVec->at(currTopicIndex)->setIsSelected(false);
                currTopicIndex--;
            }
            break;
        case GunCamGui::DOWN:
            if(currTopicIndex < topicWidVec->size()-1 )
            {
                topicWidVec->at(currTopicIndex+1)->setIsSelected(true);
                topicWidVec->at(currTopicIndex)->setIsSelected(false);
                currTopicIndex++;
            }
            break;
        case GunCamGui::START:
            for(size_t i = 0; i < topicWidVec->size(); i++)
            {
                topicWidVec->at(i)->setIsActivated(false);
            }
                
            topicWidVec->at(currTopicIndex)->setIsActivated(true);
            camWidPtr->swapTopic(topicWidVec->at(currTopicIndex)->getTopic()->toLatin1().data() );
            break;
    }


    cout << "currTopicIndex: " << currTopicIndex << endl;
}


void GunCamGui::handleArmSysSlot(bool isArmed)
{
    cout << "@GunCamGui::handleArmSysSlot(...)" << endl;
    if(isArmed)
        gunLbl->setPixmap(QPixmap("src/usar_teleop/operator_ui/res/enabled2.png") );
    else
        gunLbl->setPixmap(QPixmap("src/usar_teleop/operator_ui/res/disabled2.png") );
}


void GunCamGui::handleOpenOptSlot(bool isOpen)
{
    cout << "@GunCamGui::handleOpenOptSlot(...)" << endl;
    if(isOpen)
        ;//close options UI
    else
        ;//open optios UI
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
    delete leftPanelLay;
    delete leftPanelLayWid;
    delete outerLayout;
}
