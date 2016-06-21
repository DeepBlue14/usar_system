/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   OpConfigGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 26, 2016, 10:14 PM
 * Last Modified: 
 */

#ifndef OP_CONFIG_GUI_H
#define OP_CONFIG_GUI_H

#include <QApplication>
#include <QDesktopWidget>
#include <QRect>
#include <QScrollArea>
#include <QFile>
#include <QString>

#include <iostream>

#include "ConfigJoyGui.h"
#include "InRunGui.h"

using namespace std;

class OpConfigGui : public QScrollArea
{
    Q_OBJECT
            
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit OpConfigGui(QScrollArea* parent = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void loadPreRunOp();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void unloadPreRunOp();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void loadInRunOp();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void unloadInRunOp();
        
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
        virtual ~OpConfigGui();
        
    private slots:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void handleCloseUiEvt();
        
    private:
        ConfigJoyGui* configJoyGui;
        InRunGui* inRunGui;
};

#endif /* OP_CONFIG_GUI_H */
