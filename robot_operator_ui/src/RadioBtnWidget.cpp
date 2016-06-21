/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/robot_operator_ui/RadioBtnWidget.h"


RadioBtnWidget::RadioBtnWidget(const char* groupTitle, QStringList* radBtnNameStrLstPtr, QWidget* parent) : QWidget(parent)
{
    groupBoxPtr = new QGroupBox(groupTitle);

    this->radBtnNameStrLstPtr = new QStringList(*radBtnNameStrLstPtr);
    radBtnPtrVecPtr = new QVector<QRadioButton*>();
    
    outerLayout = new QGridLayout();
    radLayout = new QVBoxLayout();
    for(size_t i = 0; i < this->radBtnNameStrLstPtr->size(); i++)
    {
        radBtnPtrVecPtr->push_back(new QRadioButton(radBtnNameStrLstPtr->at(i) ) );
        radLayout->addWidget(radBtnPtrVecPtr->at(i) );
    }
    radBtnPtrVecPtr->at(0)->setChecked(true);
    radBtnPtrVecPtr->at(2)->setEnabled(false);
    groupBoxPtr->setLayout(radLayout);
    outerLayout->addWidget(groupBoxPtr);
    
    this->setLayout(outerLayout);
}


char* RadioBtnWidget::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


RadioBtnWidget::~RadioBtnWidget()
{
    delete groupBoxPtr;
    delete radBtnNameStrLstPtr;
    delete radBtnPtrVecPtr;
    delete outerLayout;
    delete radLayout;
}
