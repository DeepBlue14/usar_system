/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/central_control_ui/MapDataWidget.h"


MapDataWidget::MapDataWidget(QWidget* parent) : QWidget(parent)
{
    nameLbl = new QLabel("<b>Map:</b> Olsen Hall 3rd floor");
    ipAddrLbl = new QLabel("<b></b>");
    eStopBtn = new QPushButton("");
    //eStopBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    eStopBtn->setFixedSize(50+5, 50+5);
    eStopBtn->setIcon(QIcon("src/usar_teleop/central_control_ui/res/terminate_run.png") );
    eStopBtn->setIconSize(QSize(50, 50) );
    
    outerLayout = new QGridLayout();
    outerLayout->addWidget(nameLbl, 0, 0);
    outerLayout->addWidget(ipAddrLbl, 1, 0);
    outerLayout->addWidget(eStopBtn, 0, 1, 3, 1);
    
    this->setLayout(outerLayout);
}


char* MapDataWidget::toString()
{
    char* str = const_cast<char*>("***METHO STUB***");
    
    return str;
}


MapDataWidget::~MapDataWidget()
{
    ;
}
