/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   LstWidContainer.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 8, 2016, 7:04 PM
 * Last Modified: 3/25/2016
 */

#ifndef LST_WID_CONTAINER_H
#define LST_WID_CONTAINER_H

#include <QWidget>
#include <QVBoxLayout>

#include "ClientGroupWidget.h"

class LstWidContainer : public QWidget
{
    Q_OBJECT
            
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit LstWidContainer(QWidget* parent = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void addGroup(ClientGroupWidget* groupPtr);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        ClientGroupWidget* getOperators() const;
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        virtual ~LstWidContainer();
        
    private:
        ClientGroupWidget* cgw_1;
        ClientGroupWidget* cgw_2;
        QVBoxLayout* outerLayout;
};

#endif /* LST_WID_CONTAINER_H */
