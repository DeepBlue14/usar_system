/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/central_control_ui/ClientGroupWidget.h"

ClientGroupWidget::ClientGroupWidget(cct::Group group, QWidget* parent) : QWidget(parent)
{
    groupLblPtr = new QLabel("test");
    groupLstWidPtr = new QListWidget();
    vec = new QVector<QListWidgetItem*>();
    //-----------------test-----------
    for(size_t i = 0; i < 1; i++)
    {
        if(group == cct::OPERATOR)
        {
            vec->push_back(new QListWidgetItem(QIcon("src/usar_teleop/central_control_ui/res/operator.png"), "James Kuczynski") );
        }
        else
        {
            vec->push_back(new QListWidgetItem(QIcon("src/usar_teleop/central_control_ui/res/observer.png"), "Justin Wood") );
        }
        groupLstWidPtr->addItem(vec->at(i) );
    }
    //--------------------------------
    outerLayout = new QGridLayout();

    switch(group)
    {
        case cct::OPERATOR:
            groupLblPtr->setText("Agent");
            break;
        case cct::OBSERVER:
            groupLblPtr->setText("Observer");
            break;
        default:
            cerr << "ERROR @ ClientGroupWidget::ClientGroupWidget\nInvalid case in switch statement" << endl;
    }

    
    outerLayout->addWidget(groupLblPtr, 0, 0);
    outerLayout->addWidget(groupLstWidPtr, 1, 0);
    
    this->setLayout(outerLayout);
}


QListWidget* ClientGroupWidget::getGroup() const
{
    return groupLstWidPtr;
}


int ClientGroupWidget::getSelected()
{
    for(size_t i = 0; i < vec->size(); i++)
    {
        if(vec->at(i)->isSelected() )
        {
            return i;
        }
    }
    
    return 0;
}


void ClientGroupWidget::focus(int index)
{
    /*groupLstWidPtr->setStyleSheet(
            "QListWidget::item {"
                "border-style: solid;"
                "border-width:1px;"
                "border-color:black;"
                "background-color: green;"
            "}"
            "QListWidget::item:selected {"
                "background-color: red;"
            "}");*/
    groupLstWidPtr->item(index)->setSelected(true);
    //groupLstWidPtr->item(index)->setBackground(Qt::blue);
}

ClientGroupWidget::~ClientGroupWidget()
{
    ;
}
