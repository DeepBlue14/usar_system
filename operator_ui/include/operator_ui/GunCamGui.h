/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   GunCamGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 11, 2016, 4:50 PM
 * Last Modified: 3/31/2016
 */

#ifndef GUN_CAM_GUI_H
#define GUN_CAM_GUI_H

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QLabel>
#include <QIcon>
#include <QVector>
#include <QFile>
#include <QGridLayout>

#include <iostream>

#include "CamWidget.h"
#include "CCSystem.h"
#include "CustomLabel.h"
#include "HriMap.h"

using std::cout;
using std::cerr;
using std::endl;

class GunCamGui : public QWidget
{
        Q_OBJECT
         
    public:
        /**
         * Constructor.
         *
         * @param mountPanelOnLeft
         * @param parent
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit GunCamGui(bool mountPanelOnLeft = true, QWidget* parent = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void loadContent();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void unloadContent();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void mountPanelLeft(bool mountPanelOnLeft);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void setTabNameStrPtr(QString* tabNameStrPtr);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        QString* getTabNameStrPtr() const;
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void setCamWidPtr(CamWidget* camWidPtr);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        CamWidget* getCamWidPtr() const;
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        char* toString();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        virtual ~GunCamGui();
        
    public slots:
        void handleSwapTopicSlot(int buttonState);
        void handleArmSysSlot(bool isArmed);
        void handleOpenOptSlot(bool isOpen);
        
    private:
        enum TopicJoy
        {
            DOWN = -1,
            NONE,
            UP,
            START
        };
        int currTopicIndex;
        //CustomLabel* rgbLblPtr;
        //CustomLabel* scopeLblPtr;
        //CustomLabel* trackingLblPtr;
        //CustomLabel* irLblPtr;
        QVector<CustomLabel*>* topicWidVec;
        QWidget* wid;
        QLabel* mapLbl;
        HriMap* hriMap;
        QGridLayout* lay;
        CamWidget* camWidPtr;
        QLabel* gunLbl;
        QLabel* ammoCountLblPtr;
        QStringList* strLst;
        QWidget* leftPanelContainerPtr;
        QGridLayout* leftPanelLay;
        QWidget* leftPanelLayWid;
        QGridLayout* outerLayout;
};

#endif /* GUN_CAM_GUI_H */
