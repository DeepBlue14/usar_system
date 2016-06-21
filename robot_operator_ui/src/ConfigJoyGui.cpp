/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */


#include "../include/robot_operator_ui/ConfigJoyGui.h"

ConfigJoyGui::ConfigJoyGui(QWidget* parent) : QWidget(parent)
{
    xmlMasterPtr = new XmlMaster();
    lblVec = new QVector<QLabel*>();
    cbVec = new QVector<QComboBox*>();
    btnGroup = new BtnGroup();
    
    joyImgPtr = new QImage();
    joyImgPtr->load("src/usar_teleop/robot_operator_ui/res/joy_diagram.png");
    joyImgLblPtr = new QLabel();
    joyImgLblPtr->setPixmap(QPixmap::fromImage(*joyImgPtr) );

    pairLayout = new QGridLayout();
    outerLayout = new QGridLayout();
    
    connect(btnGroup->getOkBtn(), SIGNAL(released() ), this, SLOT(handleOkBtnSlot() ) );
    connect(btnGroup->getCancelBtn(), SIGNAL(released() ), this, SLOT(handleCancelBtnSlot() ) );
    connect(btnGroup->getApplyBtn(), SIGNAL(released() ), this, SLOT(handleApplyBtnSlot() ) );
    connect(btnGroup->getHelpBtn(), SIGNAL(released() ), this, SLOT(handleHelpBtnSlot() ) );
    
    // Variable cmdContPtrVecPtr contains ALL the data extracted from the XML file
    cmdContPtrVecPtr = xmlMasterPtr->config("src/usar_teleop/robot_operator_ui/res/joy_options.xml");
    xmlMasterPtr->printDat(cmdContPtrVecPtr);
    
    for(size_t i = 0; i < cmdContPtrVecPtr->size(); i++)
    {
        lblVec->push_back(new QLabel(*cmdContPtrVecPtr->at(i)->getDescStrPtr()) );
        cbVec->push_back(new QComboBox() );
        QStringList* strLst = new QStringList();
        //cout << "size_t j: " << strLstVec->at(i)->getOptionVecPtr()->size() << endl;
        for(size_t j = 0; j < cmdContPtrVecPtr->at(i)->getOptionVecPtr()->size(); j++)
        {
            //cout << strLstVec->at(i)->getOptionVecPtr()->at(j)->getDesc()->toStdString() << endl;
            strLst->push_back(*cmdContPtrVecPtr->at(i)->getOptionVecPtr()->at(j)->getDesc() );
        }
        cbVec->at(i)->addItems(*strLst);
        for(size_t j = 0; j < strLst->size(); j++)
        {
            //FIXME: this needs to set the default option
            if(cmdContPtrVecPtr->at(i)->getDefaultJoy() == cmdContPtrVecPtr->at(i)->getOptionVecPtr()->at(j)->getJoy() )
            {
                cout << "1: " << cmdContPtrVecPtr->at(i)->getDefaultJoy() << ", 2: " << cmdContPtrVecPtr->at(i)->getOptionVecPtr()->at(j)->getJoy() << endl;
                cbVec->at(i)->setCurrentIndex(j);
            }
        }
        
        
        pairLayout->addWidget(lblVec->at(i), i, 0);
        pairLayout->addWidget(cbVec->at(i), i, 1);
    }
    //cout << "^^^size: " << cmdContPtrVecPtr->size() << endl;
    
    outerLayout->addLayout(pairLayout, 0, 0, Qt::AlignHCenter);
    outerLayout->addWidget(joyImgLblPtr, 1, 0, Qt::AlignHCenter);
    outerLayout->addWidget(btnGroup, 2, 0, Qt::AlignRight);
    
    this->setLayout(outerLayout);
}


void ConfigJoyGui::collectCurrentSettings()
{
    for(size_t i = 0; i < cbVec->size(); i++)
    {
        cout << cbVec->at(i)->currentIndex() << endl;
        cout << cbVec->at(i)->currentText().toStdString() << endl;
        //dat::dataVec->at(i)->cmd
    }
}


void ConfigJoyGui::handleOkBtnSlot()
{
    cout << "@handleOkBtnSlot()" << endl;
    //save data
    collectCurrentSettings();
    emit closeUi();
}


void ConfigJoyGui::handleCancelBtnSlot()
{
    cout << "@handleCancelBtnSlot()" << endl;
    emit closeUi();
}


void ConfigJoyGui::handleApplyBtnSlot()
{
    cout << "@handleApplyBtnSlot()" << endl;
    //save data
    collectCurrentSettings();
}


void ConfigJoyGui::handleHelpBtnSlot()
{
    cout << "@handleHelpBtnSlot()" << endl;
    //launch help dialog
}


void ConfigJoyGui::loadConfigOptions()
{
    ;
}


char* ConfigJoyGui::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


ConfigJoyGui::~ConfigJoyGui()
{
    for(size_t i = 0; i < cbVec->size(); i++)
    {
        delete cbVec->at(i);
    }
    delete cbVec;

    //...
    
    delete joyImgPtr;
    delete joyImgLblPtr;
    delete pairLayout;
    delete outerLayout;
}
