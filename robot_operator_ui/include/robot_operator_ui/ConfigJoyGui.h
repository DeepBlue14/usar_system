/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   ConfigJoyGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This is the "master" GUI; the one which is launched from
 *                   the driver function.
 *
 * Created on March 2, 2016, 11:34 PM
 * Last Modified: 3/25/2016
 */

#ifndef CONFIG_JOY_GUI
#define CONFIG_JOY_GUI

#include <QWidget>
#include <QComboBox>
#include <QStringList>
#include <QVector>
#include <QImage>
#include <QLabel>
#include <QFile>
#include <QGridLayout>

#include <iostream>

#include "XmlMaster.h"
#include "CmdCont.h"
#include "BtnGroup.h"

using std::cout;
using std::cerr;
using std::endl;

class ConfigJoyGui : public QWidget
{
    Q_OBJECT
    
    signals:
        void closeUi();
    
    public:
        /**
         * Constructor.
         *
         * @param parent Refernece to parent type
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit ConfigJoyGui(QWidget* parent = 0);
        
        /**
         * Saves the current selected items from the configuration dialog.
         *
         * <dt><b>Pre: The XML parser has correctly populated the dialog.<b></dd>
         * <dt><b>Post: The new selections will be stored in memory.<b></dd>
         */
        void collectCurrentSettings();
        
        /**
         * Classic Java-style toString() method.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         * @return data contained within this class.
         */
        char* toString();
        
        /**
         * Destructor.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: Destroyes all member variables within the object.<b></dd>
         */
        virtual ~ConfigJoyGui();
        
    public slots:
        /**
         * QT slot triggered when the OK button is selected.
         * @see #okBtn
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: The new selections will be saved, and the dialog will
         *        be closed.<b></dd>
         */
        void handleOkBtnSlot();
        
        /**
         * QT slot triggered when the Cancel button is selected.
         * @see #cancelBtn
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: The dialog will terminate<b></dd>
         *
         */
        void handleCancelBtnSlot();
        
        /**
         * QT slot triggered when the Apply button is triggered.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: The new selections wil be saved<b></dd>
         *
         */
        void handleApplyBtnSlot();
        
        /**
         * QT slot triggered when the Help button is triggered.
         * @see helpBtn
         *
         * TODO: this method is merely a stub.  Triggering it will not do
         *       anything.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         */
        void handleHelpBtnSlot();
        
    private:
        /**
         * Method stub.  Calling it will not do anything.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         */
        void loadConfigOptions();
        
        XmlMaster* xmlMasterPtr;
        QVector<CmdCont*>* cmdContPtrVecPtr;
        
        QVector<QLabel*>* lblVec;
        //create parallel vector
        
        QVector<QComboBox*>* cbVec;
        BtnGroup* btnGroup;
        //QVector<QLabel*>* runOptLblVec;
        //QVector<QComboBox*>* runOptCbVec;
        
        QImage* joyImgPtr;
        QLabel* joyImgLblPtr;
        QGridLayout* pairLayout;
        QGridLayout* outerLayout;
        
};

#endif /* CONFIG_JOY_GUI */
