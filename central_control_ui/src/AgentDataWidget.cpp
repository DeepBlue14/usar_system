/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/central_control_ui/AgentDataWidget.h"


AgentDataWidget::AgentDataWidget(QWidget* parent) : QWidget(parent)
{
    nameLbl = new QLabel("<b>Agent:</b> James Thomas");
    ipAddrLbl = new QLabel("<b>IP:</b> 10.0.3.11");
    overrideBtn = new QPushButton("");
    eStopBtn = new QPushButton("");
    //eStopBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    overrideBtn->setFixedSize(50+5, 50+5);
    overrideBtn->setIcon(QIcon("src/usar_teleop/central_control_ui/res/override.png") );
    overrideBtn->setIconSize(QSize(50, 50) );
    eStopBtn->setFixedSize(50+5, 50+5);
    eStopBtn->setIcon(QIcon("src/usar_teleop/central_control_ui/res/estop.png") );
    eStopBtn->setIconSize(QSize(50, 50) );
    
    outerLayout = new QGridLayout();
    outerLayout->addWidget(nameLbl, 0, 0);
    outerLayout->addWidget(ipAddrLbl, 1, 0);
    outerLayout->addWidget(overrideBtn, 0, 1, 3, 1);
    outerLayout->addWidget(eStopBtn, 0, 2, 3, 1);
    
    this->setLayout(outerLayout);
}


char* AgentDataWidget::toString()
{
    char* str = const_cast<char*>("***METHO STUB***");
    
    return str;
}


AgentDataWidget::~AgentDataWidget()
{
    ;
}
