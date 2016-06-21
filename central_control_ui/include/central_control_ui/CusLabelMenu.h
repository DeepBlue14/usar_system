/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CLabelMenu.h
 * Author: csrobot
 *
 * Created on March 26, 2016, 4:29 PM
 */

#ifndef CUS_LABEL_MENU_H
#define CUS_LABEL_MENU_H

#include <QMenu>

#include <iostream>


using namespace std;

class CusLabelMenu : public QWidget
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
        void handleOpenMenuSlot();
        void handleHideMenuSlot();
        void handleDeleteMenuSlot();
        void handleRenameMenuSlot();
        void handleRefactorMenuSlot();
        void handleAddMenuSlot();
        void handleCommitMenuSlot();
        void handleRemoveMenuSlot();
        void handlePropertiesMenuSlot();
        
    public:
        /**
         * Constructor.
         */
        CusLabelMenu(QWidget* parent = 0);
        
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
        ~CusLabelMenu();
};

#endif /* CUSLABELMENU_H */
