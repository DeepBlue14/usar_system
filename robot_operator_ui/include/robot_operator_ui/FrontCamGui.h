/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   CamTab.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This widget will contain a video window and its
 *                   corresponding configuration widgets.
 *
 * Created on March 3, 2016, 9:40 AM
 * Last Modified: 3/08/2016
 */

#ifndef FRONT_CAM_GUI_H
#define FRONT_CAM_GUI_H


#include <QWidget>
#include <QString>
#include <QStringList>
#include <QPushButton>
#include <QButtonGroup>
#include <QVector>
#include <QRadioButton>
#include <QGridLayout>

#include "RadioBtnWidget.h"
#include "CamWidget.h"

class CamWidget;

class FrontCamGui : public QWidget
{
    Q_OBJECT
         
    public:
        /**
         * Constructor.
         *
         * @param mountPanelOnLeft specify if the option panel should be
         *                         placed on the left or right.
         * @param parent instance of parent type.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: Instantates the member variables of this class.<b></dd>
         */
        explicit FrontCamGui(bool mountPanelOnLeft = true, QWidget* parent = 0);
        
        /**
         * Loads the widgets of this UI.  **METHOD STUB**
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: The UI has been setup.<b></dd>
         */
        void loadContent();
        
        /**
         * Unloads the widgets from this UI.  **METHOD STUB**
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: The widgets will be removed from the UI<b></dd>
         */
        void unloadContent();
        
        /**
         * Mutator.
         * @param tabNameStrPtr name of this UI, to be put on a label.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: Sets the member variable.<b></dd>
         */
        void setTabNameStrPtr(QString* tabNameStrPtr);
        
        /**
         * Accessor.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         * @return the name of this UI.
         */
        QString* getTabNameStrPtr() const;
        
        /**
         * Mutator
         *
         * @param camWidPtr widget streaming and displaying video from ROS.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void setCamWidPtr(CamWidget* camWidPtr);
        
        /**
         * Accessor.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         * @return camWidPtr
         */
        CamWidget* getCamWidPtr() const;
        
        /**
         * Classic Java-style toString() method.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         * @return relevent data about this classes variables.
         */
        char* toString();
        
        /**
         * Destructor.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: All member variables of this object will be deleted<b></dd>
         */
        virtual ~FrontCamGui();
        
    private:
        CamWidget* camWidPtr;
        QPushButton* optionBtnPtr;
        RadioBtnWidget* radBtnWidPtr;
        QWidget* leftPanelContainerPtr;
        QStringList* strLst;
        QGridLayout* leftPanelLay;
        QGridLayout* outerLayout;
};

#endif /* FRONT_CAM_GUI_H */
