/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/central_control_ui/LstWidItemMenu.h"


LstWidItemMenu::LstWidItemMenu(QWidget* parent) : QWidget(parent)
{
    initMenu();
}


void LstWidItemMenu::initMenu()
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


void LstWidItemMenu::handleOpenMenuSlot()
{
    cout << "LstWidItemMenu::handleOpenMenuSlot() triggered" << endl;
}


void LstWidItemMenu::handleHideMenuSlot()
{
    cout << "LstWidItemMenu::handleHideMenuSlot() triggered" << endl;
}


void LstWidItemMenu::handleDeleteMenuSlot()
{
    cout << "LstWidItemMenu::handleDeleteMenuSlot() triggered" << endl;
}


void LstWidItemMenu::handleRenameMenuSlot()
{
    cout << "LstWidItemMenu::handleRenameMenuSlot() triggered" << endl;
}


void LstWidItemMenu::handleRefactorMenuSlot()
{
    cout << "LstWidItemMenu::handleRefactorMenuSlot() triggered" << endl;
}


void LstWidItemMenu::handleAddMenuSlot()
{
    cout << "LstWidItemMenu::handleAddMenuSlot() triggered" << endl;
}


void LstWidItemMenu::handleCommitMenuSlot()
{
    cout << "LstWidItemMenu::handleCommitMenuSlot() triggered" << endl;
}


void LstWidItemMenu::handleRemoveMenuSlot()
{
    cout << "LstWidItemMenu::handleRemoveMenuSlot() triggered" << endl;
}


void LstWidItemMenu::handlePropertiesMenuSlot()
{
    //cout << "LstWidItemMenu::handlePropertiesMenuSlot() triggered" << endl;
//    filePropGuiPtr->setFileNameStrPtr(fileNameStrPtr);
//    filePropGuiPtr->setFileLocStrPtr(fileLocStrPtr);
//    filePropGuiPtr->setLastModdedStrPtr(lastModdedStrPtr);
//    
//    filePropGuiPtr->fillUiComponents();
//    
//    filePropGuiPtr->show();
    ;
}


QMenu* LstWidItemMenu::getMenu()
{
    return menu;
}


void LstWidItemMenu::setFileNameStrPtr(QString* fileChosenStrPtr)
{
    this->fileNameStrPtr = fileChosenStrPtr;
}
        
        
QString* LstWidItemMenu::getFileNameStrPtr()
{
    return fileNameStrPtr;
}


void LstWidItemMenu::setFileLocStrPtr(QString* fileLocStrPtr)
{
    this->fileLocStrPtr = fileLocStrPtr;
}


QString* LstWidItemMenu::getFileLocStrPtr()
{
    return fileLocStrPtr;
}


void LstWidItemMenu::setLastModdedStrPtr(QString* lastModdedStrPtr)
{
    this->lastModdedStrPtr = lastModdedStrPtr;
}
        
        
QString* LstWidItemMenu::getLastModdedStrPtr()
{
    return lastModdedStrPtr;
}


LstWidItemMenu::~LstWidItemMenu()
{
    ;
}