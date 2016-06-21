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
 * File Description: This is the "master" GUI; the one which is launched from
 *                   the driver function.
 *
 * Created on March 2, 2016, 11:34 PM
 * Last Modified: 
 */

#ifndef MASTER_GUI_H
#define MASTER_GUI_H

#include <ros/ros.h>

#include <QTimer>
#include <QMainWindow>
#include <QtWidgets/QWidget>
#include <QSplitter>
#include <QTabWidget>
#include <QtCore/QString>
#include <QGridLayout>

#include "CentralWidget.h"

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
        char* toString();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        virtual ~MasterGui();
        
    protected:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void timerEvent(QTimerEvent* event); // "Master" gui needs this
        
    private:
        QBasicTimer eventTimer; // "Master" gui needs this
        //FrontCamGui* leftCamGuiPtr;
        //QGridLayout* outerLayout;
        CentralWidget* centralWidgetPtr;
};

#endif /* MASTER_GUI_H */
