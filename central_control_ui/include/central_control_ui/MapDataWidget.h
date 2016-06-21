/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   MapDataWidget.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description:
 *
 * Created on March 26, 2016, 12:29 PM
 * Last Modified: 3/26/2016
 */

#ifndef MAP_DATA_WIDGET_H
#define MAP_DATA_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class MapDataWidget : public QWidget
{
    Q_OBJECT
            
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit MapDataWidget(QWidget* parent = 0);
        
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
        virtual ~MapDataWidget();
        
    private:
        QLabel* nameLbl;
        QLabel* ipAddrLbl;
        QPushButton* eStopBtn;
        QGridLayout* outerLayout;
};

#endif /* MAP_DATA_WIDGET_H */
