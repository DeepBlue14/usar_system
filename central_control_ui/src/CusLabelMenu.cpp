/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/central_control_ui/CusLabelMenu.h"


CusLabelMenu::CusLabelMenu(QWidget* parent) : QWidget(parent)
{
    initMenu();
}


void CusLabelMenu::initMenu()
{
    menu = new QMenu();
    
    fileNameStrPtr = new QString("null");
    fileLocStrPtr = new QString("null");
    lastModdedStrPtr = new QString("null");
    
    //this->addAction("Open");
    openAct = new QAction(tr("&Open"), this);
    //openAct->setShortcut(QKeySequence::Open);
    openAct->setStatusTip("Open file");
    connect(openAct, SIGNAL(triggered()), this, SLOT(handleOpenMenuSlot() ) );
    menu->addAction(openAct);
    
    hideAct = new QAction(tr("&Hide"), this);
    //hideAct->setShortcut(QKeySequence::Close);
    hideAct->setStatusTip("Hide file");
    connect(hideAct, SIGNAL(triggered()), this, SLOT(handleHideMenuSlot() ) );
    menu->addAction(hideAct);

    deleteAct = new QAction(tr("&Delete"), this);
    //deleteAct->setShortcut(QKeySequence::Delete);
    deleteAct->setStatusTip("Delete file");
    connect(deleteAct, SIGNAL(triggered()), this, SLOT(handleDeleteMenuSlot() ) );
    menu->addAction(deleteAct);
    
    renameAct = new QAction(tr("&Rename..."), this);
    //renameAct->setShortcut()
    renameAct->setStatusTip("Rename file");
    connect(renameAct, SIGNAL(triggered()), this, SLOT(handleRenameMenuSlot() ) );
    menu->addAction(renameAct);
    
    refactorAct = new QAction(tr("&Refactor"), this);
    //refactorAct->setShortcut()
    refactorAct->setStatusTip("Refactor");
    connect(refactorAct, SIGNAL(triggered()), this, SLOT(handleRefactorMenuSlot() ) );
    menu->addAction(refactorAct);
    
    QMenu* gitMenu = menu->addMenu("Git");
    
    addAct = new QAction(tr("&Add"), this);
    connect(addAct, SIGNAL(triggered()), this, SLOT(handleAddMenuSlot() ) );
    gitMenu->addAction(addAct);
    
    commitAct = new QAction(tr("Commit"), this);
    connect(commitAct, SIGNAL(triggered()), this, SLOT(handleCommitMenuSlot() ) );
    gitMenu->addAction(commitAct);
    
    removeAct = new QAction(tr("&Remove"), this);
    connect(removeAct, SIGNAL(triggered()), this, SLOT(handleRemoveMenuSlot() ) );
    gitMenu->addAction(removeAct);
    
    propertiesAct = new QAction(tr("&Properties"), this);
    connect(propertiesAct, SIGNAL(triggered()), this, SLOT(handlePropertiesMenuSlot() ) );
    menu->addAction(propertiesAct);
    
   // filePropGuiPtr = new FilePropGui();
    
    
}


void CusLabelMenu::handleOpenMenuSlot()
{
    cout << "CusLabelMenu::handleOpenMenuSlot() triggered" << endl;
}


void CusLabelMenu::handleHideMenuSlot()
{
    cout << "CusLabelMenu::handleHideMenuSlot() triggered" << endl;
}


void CusLabelMenu::handleDeleteMenuSlot()
{
    cout << "CusLabelMenu::handleDeleteMenuSlot() triggered" << endl;
}


void CusLabelMenu::handleRenameMenuSlot()
{
    cout << "CusLabelMenu::handleRenameMenuSlot() triggered" << endl;
}


void CusLabelMenu::handleRefactorMenuSlot()
{
    cout << "CusLabelMenu::handleRefactorMenuSlot() triggered" << endl;
}


void CusLabelMenu::handleAddMenuSlot()
{
    cout << "CusLabelMenu::handleAddMenuSlot() triggered" << endl;
}


void CusLabelMenu::handleCommitMenuSlot()
{
    cout << "CusLabelMenu::handleCommitMenuSlot() triggered" << endl;
}


void CusLabelMenu::handleRemoveMenuSlot()
{
    cout << "CusLabelMenu::handleRemoveMenuSlot() triggered" << endl;
}


void CusLabelMenu::handlePropertiesMenuSlot()
{
    //cout << "CusLabelMenu::handlePropertiesMenuSlot() triggered" << endl;
//    filePropGuiPtr->setFileNameStrPtr(fileNameStrPtr);
//    filePropGuiPtr->setFileLocStrPtr(fileLocStrPtr);
//    filePropGuiPtr->setLastModdedStrPtr(lastModdedStrPtr);
//    
//    filePropGuiPtr->fillUiComponents();
//    
//    filePropGuiPtr->show();
    ;
}


QMenu* CusLabelMenu::getMenu()
{
    return menu;
}


void CusLabelMenu::setFileNameStrPtr(QString* fileChosenStrPtr)
{
    this->fileNameStrPtr = fileChosenStrPtr;
}
        
        
QString* CusLabelMenu::getFileNameStrPtr()
{
    return fileNameStrPtr;
}


void CusLabelMenu::setFileLocStrPtr(QString* fileLocStrPtr)
{
    this->fileLocStrPtr = fileLocStrPtr;
}


QString* CusLabelMenu::getFileLocStrPtr()
{
    return fileLocStrPtr;
}


void CusLabelMenu::setLastModdedStrPtr(QString* lastModdedStrPtr)
{
    this->lastModdedStrPtr = lastModdedStrPtr;
}
        
        
QString* CusLabelMenu::getLastModdedStrPtr()
{
    return lastModdedStrPtr;
}


CusLabelMenu::~CusLabelMenu()
{
    ;
}