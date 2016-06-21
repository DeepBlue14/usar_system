/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   MasterGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 8, 2016, 6:12 PM
 * Last Modified: 3/25/2016
 */

#ifndef MASTER_GUI_H
#define MASTER_GUI_H

#include <ros/ros.h>

#include <QTimer>
#include <QMainWindow>
#include <QStatusBar>
#include <QScrollArea>
#include <QDockWidget>

#include "LstWidContainer.h"
#include "CamGroupGui.h"
#include "CentralWidget.h"

#include <iostream>

using namespace std;

class MasterGui : public QMainWindow
{
    Q_OBJECT
            
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit MasterGui(QMainWindow* parent = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        virtual ~MasterGui();
        
    public slots:
        void test_slot_2();
    
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void moveStuff(int index);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void operatorWasTriggered();
        
    protected:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void wheelEvent(QWheelEvent* event);
        
        void timerEvent(QTimerEvent* event);
        
    private:
        QBasicTimer eventTimer;
        CentralWidget* centralWidPtr;
        CamGroupGui* camGroupGuiPtr;
        LstWidContainer* lstWidContPtr;
};

#endif /* MASTER_GUI_H */
