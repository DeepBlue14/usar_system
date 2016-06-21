/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   ClientGroupWidget.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 8, 2016, 6:43 PM
 * Last Modified: 3/25/2016
 */

#ifndef CLIENT_GROUP_WIDGET_H
#define CLIENT_GROUP_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include <QGridLayout>

#include <iostream>

#include "CCTypes.h"

using std::cout;
using std::cerr;
using std::endl;

class ClientGroupWidget : public QWidget
{
    Q_OBJECT
            
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit ClientGroupWidget(cct::Group group, QWidget* parent = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void focus(int index = 0);
        
        //QLabel* getOperators() const;
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        QListWidget* getGroup() const;
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        int getSelected();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        virtual ~ClientGroupWidget();
        
    private:
        QLabel* groupLblPtr;
        QListWidget* groupLstWidPtr;
        QVector<QListWidgetItem*>* vec;
        QGridLayout* outerLayout;
        
};

#endif /* CLIENT_GROUP_WIDGET_H */
