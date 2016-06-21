/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   CustomLabel.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 22, 2016, 6:05 PM
 * Last Modified: 3/25/2016
 */

#ifndef CUSTOM_LABEL_H
#define CUSTOM_LABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPoint>

#include <iostream>

#include "CusLabelMenu.h"

using namespace std;

class CustomLabel : public QLabel
{
    Q_OBJECT
            
    signals:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void mousePressed(const QPoint& );
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void iWasClicked(int index);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void swapUiMode();
    
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        CustomLabel(int index, QWidget* parent = 0, Qt::WindowFlags f = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        CustomLabel(int index, const QString& text, QWidget* parent = 0, Qt::WindowFlags f = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        int getIndex() const;
        
    protected:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void mousePressEvent(QMouseEvent* ev);
        
    private:
        int index;
        CusLabelMenu* clu;
};

#endif /* CUSTOM_LABEL_H */
