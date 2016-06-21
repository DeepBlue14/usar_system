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
 * Created on March 22, 2016, 9:29 AM
 * Last Modified: 3/25/2016
 */

#ifndef CENTRAL_WIDGET_H
#define CENTRAL_WIDGET_H

#include <QWidget>
#include <QGridLayout>

#include <iostream>

#include "CamGui.h"
#include "MapGui.h"

using namespace std;

class CentralWidget : public QWidget
{
    Q_OBJECT
            
    public:
        enum Mode
        {
            TWIN,
            MAP
        };
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit CentralWidget(QWidget* parent = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void loadTwinMode();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void unloadTwinMode();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void loadMapMode();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void unloadMapMode();
        
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
        virtual ~CentralWidget();
        
    public slots:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void callback();
        
    private:
        Mode currentMode;
        CamGui* camGuiPtr;
        MapGui* mapGuiPtr;
        QGridLayout* outerLayout;
};

#endif /* CENTRAL_WIDGET_H */
