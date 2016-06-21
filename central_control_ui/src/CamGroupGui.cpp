/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/central_control_ui/CamGroupGui.h"

CamGroupGui::CamGroupGui(QWidget* parent) : QWidget(parent)
{
    indexCounter = 0;
    camVecPtr = new QVector<CamWidget*>();
    
    outerLayout = new QGridLayout();
    //--------------test----------------
    for(size_t i = 0; i < 1; i++)
    {
        camVecPtr->push_back(new CamWidget(indexCounter++, "src/usar_teleop/central_control_ui/res/place_holder_small.jpg") );
        camVecPtr->at(i)->addBorder();
        camVecPtr->at(i)->unfocus();
        if(i < 5)//6: hardcoded 
        {
            outerLayout->addWidget(camVecPtr->at(i), 0, i);
        }
        else
        {
            cout << "@CamGroupGui:CamGroupGui(...): adding to level two" << endl;
            outerLayout->addWidget(camVecPtr->at(i), 1, i-5);
        }
    }
    camVecPtr->at(0)->focus();
    //----------------------------------
    
    for(size_t i = 0; i < camVecPtr->size(); i++)
    {
        connect(camVecPtr->at(i)->getLabel(), SIGNAL(iWasClicked(int ) ), this, SLOT(callback(int ) ) );
    }
    
    this->setLayout(outerLayout);
}


void CamGroupGui::callback(int index)
{
    for(size_t i = 0; i < camVecPtr->size(); i++)
    {
        if(camVecPtr->at(i)->getLabel()->getIndex() != index)
        {
            camVecPtr->at(i)->unfocus();
        }
        else
        {
            //highlight the correct agent?
        }
    }
    
    emit modUi(index);
}


QVector<CamWidget*>* CamGroupGui::getCamVecPtr() const
{
    return camVecPtr;
}


CamGroupGui::~CamGroupGui()
{
    ;
}
