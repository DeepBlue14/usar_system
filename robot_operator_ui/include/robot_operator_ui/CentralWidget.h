/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   CentralWidget.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 10, 2016, 12:45 AM
 * Last Modified: 3/11/2016
 */

#ifndef CENTRAL_WIDGET_H
#define CENTRAL_WIDGET_H

#include <QMainWindow>
#include <QtWidgets/QWidget>
#include <QSplitter>
#include <QTabWidget>
#include <QtCore/QString>
#include <QGridLayout>
#include <QKeyEvent>

#include <iostream>

#include "MapGui.h"
#include "FrontCamGui.h"
#include "GunCamGui.h"

using namespace std;

class CentralWidget : public QWidget
{
    Q_OBJECT
            
    public:
        /**
         * Constructor.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: Member variables will be initialized.<b></dd>
         */
        explicit CentralWidget(QWidget* parent = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         * @return data of this object.
         */
        char* toString();
        
        /**
         * Destructor.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: Deletes member variables.<b></dd>
         */
        virtual ~CentralWidget();
        
    protected:
        void keyPressEvent(QKeyEvent* event);
        
    private:
        /**
         * Loads/re-loades the UI in tab mode.
         *
         * <dt><b>Pre:<b></dd>
         * <dt><b>Post:<b></dd>
         */
        void loadTabMode();
        
        /**
         * Unloades the UI.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: UI elements are set invisible and uneditable.<b></dd>
         */
        void unloadTabMode();
        
        /**
         * Loads/re-loads the UI in paralel window mode.
         *
         * <dt><b>Pre:<b></dd>
         * <dt><b>Post:<b></dd>
         */
        void loadWinMode();
        
         /**
         * Unloades the UI.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: UI elements are set invisible and uneditable.<b></dd>
         */
        void unloadWinMode();
    
        bool isTabMode;
        bool mapIsHidden;
        QSplitter* vertSplitter;
        QSplitter* horizSplitter;
        MapGui* leftCamGuiPtr;
        GunCamGui* rightGunGuiPtr;
        FrontCamGui* rightGunGuiPtr2;
        QTabWidget* tabWidgetPtr;
        QGridLayout* outerLayout;
};

#endif /* CENTRAL_WIDGET_H */
