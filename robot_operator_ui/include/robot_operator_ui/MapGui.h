/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   MapTab.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This widget will contain a video window and its
 *                   corresponding configuration widgets.
 *
 * Created on March 3, 2016, 9:40 AM
 * Last Modified: 3/08/2016
 */

#ifndef MAP_GUI_H
#define MAP_GUI_H


#include <QWidget>
#include <QString>
#include <QStringList>
#include <QPushButton>
#include <QLabel>
#include <QImage>
#include <QButtonGroup>
#include <QVector>
#include <QRadioButton>
#include <QGridLayout>

#include "RadioBtnWidget.h"
#include "MapWidget.h"
#include "OpConfigGui.h"

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
        explicit MapGui(bool mountPanelOnLeft = true, QWidget* parent = 0);
        
       /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void loadContent();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void unloadContent();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void setTabNameStrPtr(QString* tabNameStrPtr);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        QString* getTabNameStrPtr() const;
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void setCamWidPtr(MapWidget* camWidPtr);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        MapWidget* getCamWidPtr() const;
        
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
        
    private slots:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void handleOptionBtnPtrSlot();
        
    private:
        MapWidget* camWidPtr;
        QPushButton* optionBtnPtr;
        OpConfigGui* opConfigGuiPtr;
        RadioBtnWidget* radBtnWidPtr;
        QWidget* leftPanelContainerPtr;
        QLabel* status;
        QLabel* robotStat;
        QLabel* robotLbl;
        QLabel* gunStat;
        QLabel* gunLbl;
        QLabel* comdrStat;
        QLabel* comdrLbl;
        QStringList* strLst;
        QGridLayout* leftPanelLay;
        QGridLayout* statusLay;
        QGridLayout* outerLayout;
};

#endif /* MAP_GUI_H */
