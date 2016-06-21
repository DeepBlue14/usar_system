/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   CamGroupGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 21, 2016, 10:37 PM
 * Last Modified: 3/25/2016
 */

#ifndef CAM_GROUP_GUI_H
#define CAM_GROUP_GUI_H

#include <QWidget>
#include <QFrame>
#include <QVector>
#include <QGridLayout>

#include "CamWidget.h"

class CamGroupGui : public QWidget
{
    Q_OBJECT
            
    signals:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void modUi(int index);
    
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit CamGroupGui(QWidget* parent = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        QVector<CamWidget*>* getCamVecPtr() const;
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        virtual ~CamGroupGui();
        
    public slots:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void callback(int index);
        
    private:
        int indexCounter;
        QVector<CamWidget*>* camVecPtr;
        QGridLayout* outerLayout;
};

#endif /* CAM_GROUP_GUI_H */
