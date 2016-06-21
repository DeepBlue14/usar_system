/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   MapWidget.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This widget adds a layer of abstraction to the development
 *                   process, handling the ROS --> QT conversions behind the
 *                   scenes for video processing.
 *
 * Created on March 8, 2016, 4:40 PM
 * Last Modified: 3/25/2016
 */

#ifndef MAP_WIDGET_H
#define MAP_WIDGET_H

#include <QWidget>
#include <QImage>
#include <QFrame>
#include <QString>
#include <QGridLayout>

#include <iostream>

#include "CCSystem.h"
#include "CustomLabel.h"

using namespace std;

class MapWidget : public QWidget
{
    Q_OBJECT
            
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit MapWidget(int index, const char* defaultImgStr, QWidget* parent = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void addBorder();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void focus();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void unfocus();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void resizeImage();
        
        
        void setMap(const char* mapImagePath, bool resize);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        CustomLabel* getLabel() const;
        
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
        virtual ~MapWidget();
        
    private:
        QImage* imagePtr;
        CustomLabel* imageContainerLblPtr;
        QGridLayout* outerLayout;
};

#endif /* MAP_WIDGET_H */
