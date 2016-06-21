/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   MapGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 21, 2016, 7:19 PM
 * Last Modified: 3/25/2016
 */

#ifndef MAP_GUI_H
#define MAP_GUI_H

#include <QWidget>
#include <QGridLayout>

#include "MapWidget.h"
#include "MapDataWidget.h"

class MapGui : public QWidget
{
    Q_OBJECT
            
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit MapGui(const char* fileName, QWidget* parent = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        MapWidget* getMapWidget() const;
        
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
        virtual ~MapGui();
        
        private:
            MapWidget* mapWidPtr;
            MapDataWidget* mapDatWidPtr;
            QGridLayout* outerLayout;
};

#endif /* MAP_GUI_H */
