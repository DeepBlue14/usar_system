/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/central_control_ui/LstWidContainer.h"


LstWidContainer::LstWidContainer(QWidget* parent) : QWidget(parent)
{
    cgw_1 = new ClientGroupWidget(cct::OPERATOR);
    cgw_2 = new ClientGroupWidget(cct::OBSERVER);
    cgw_1->focus();
    
    outerLayout = new QVBoxLayout();
    outerLayout->addWidget(cgw_1);
    outerLayout->addWidget(cgw_2);
    
    this->setLayout(outerLayout);
}


void LstWidContainer::addGroup(ClientGroupWidget* groupPtr)
{
    outerLayout->addWidget(groupPtr);
}


ClientGroupWidget* LstWidContainer::getOperators() const
{
    return cgw_1;
}


LstWidContainer::~LstWidContainer()
{
    ;
}