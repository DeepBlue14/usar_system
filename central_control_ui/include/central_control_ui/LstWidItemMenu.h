/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LstWidItemMenu.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: Menu to appear when...
 *
 * Created on March 26, 2016, 4:43 PM
 */


#ifndef LST_WID_ITEM_MENU_H
#define LST_WID_ITEM_MENU_H

#include <QMenu>

#include <iostream>

using namespace std;

class LstWidItemMenu : public QWidget
{
    Q_OBJECT
    
    private:
        QMenu* menu;
        QAction* openAct;
        QAction* hideAct;
        QAction* deleteAct;
        QAction* renameAct;
        QAction* refactorAct;
        QAction* addAct;
        QAction* commitAct;
        QAction* removeAct;
        QAction* propertiesAct;
        
        QString* fileNameStrPtr;
        QString* fileLocStrPtr;
        QString* lastModdedStrPtr;
        
        //FilePropGui* filePropGuiPtr;
        
    private slots:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void handleOpenMenuSlot();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void handleHideMenuSlot();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void handleDeleteMenuSlot();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void handleRenameMenuSlot();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void handleRefactorMenuSlot();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void handleAddMenuSlot();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void handleCommitMenuSlot();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void handleRemoveMenuSlot();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void handlePropertiesMenuSlot();
        
    public:
        /**
         * Constructor.
         */
        LstWidItemMenu(QWidget* parent = 0);
        
        /**
         * Inits the menu for a file.
         */
        void initMenu();
        
        /**
         * 
         * 
         * @return 
         */
        QMenu* getMenu();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void setFileNameStrPtr(QString* fileNameStrPtr);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        QString* getFileNameStrPtr();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void setFileLocStrPtr(QString* fileLocStrPtr);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        QString* getFileLocStrPtr();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void setLastModdedStrPtr(QString* lastModdedStrPtr);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        QString* getLastModdedStrPtr();
        
        /**
         * Destructor.
         */
        ~LstWidItemMenu();
};

#endif /* LST_WID_ITEM_MENU_H */
