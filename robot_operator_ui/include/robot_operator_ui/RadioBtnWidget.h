/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   RadioBtnWidget.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: Container class to hold a group of radio buttons.
 *
 * Created on March 4, 2016, 3:02 PM
 */

#ifndef RADIO_BTN_WIDGET_H
#define RADIO_BTN_WIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QIcon>
#include <QRadioButton>
#include <QVector>
#include <QStringList>
#include <QVBoxLayout>
#include <QGridLayout>

class RadioBtnWidget : public QWidget
{
    Q_OBJECT
            
    public:
        /**
         * Constructor.
         * @param groupTitle
         * @param radBtnNameStrLstPtr
         * @param parent
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit RadioBtnWidget(const char* groupTitle, QStringList* radBtnNameStrLstPtr, QWidget* parent = 0);
        
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
        virtual ~RadioBtnWidget();
        
    private:
        QGroupBox* groupBoxPtr;
        QVBoxLayout* radLayout;
        QStringList* radBtnNameStrLstPtr;
        QVector<QRadioButton*>* radBtnPtrVecPtr;
        QGridLayout* outerLayout;
};

#endif /* RADIO_BTN_WIDGET_H */
