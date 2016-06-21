/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   CamGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 21, 2016, 7:19 PM
 * Last Modified: 3/25/2016
 */

#ifndef CAM_GUI_H
#define CAM_GUI_H

#include <QWidget>
#include <QGridLayout>

#include "CamWidget.h"
#include "AgentDataWidget.h"

class CamGui : public QWidget
{
    Q_OBJECT
            
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit CamGui(const char* fileName, QWidget* parent = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        CamWidget* getCamWidget() const;
        
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
        virtual ~CamGui();
        
        private:
            CamWidget* camWidPtr;
            AgentDataWidget* agentDatWidPtr;
            QGridLayout* outerLayout;
};

#endif /* CAM_GUI_H */
