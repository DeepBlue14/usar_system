/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/operator_ui/CustomLabel.h"


CustomLabel::CustomLabel(const char* name, const char* topic, QWidget* parent)
{
    this->name = new QString(name);
    this->topic = new QString(topic);
    isSelected = false;
    isActivated = false;
    iconLblPtr = new QLabel();
    textLblPtr = new QLabel(buildHtmlDat() );
    outerLayout = new QHBoxLayout();
    outerLayout->addWidget(iconLblPtr);
    outerLayout->addWidget(textLblPtr);
    
    this->setLayout(outerLayout);
    //cout << "@CustomLabel::CustomLabel(...); finished constructor" << endl;
}


QString CustomLabel::buildHtmlDat()
{
    QString tmp1("<font size=\"5\" color=\"");

    if(isSelected)
        tmp1.append("green");
    else
        tmp1.append("red");
        

    tmp1.append("\"><b>");
    tmp1.append(name);
    tmp1.append("<b></font>");

    return tmp1;
}


void CustomLabel::setIsSelected(bool isSelected)
{
    this->isSelected = isSelected;
    textLblPtr->setText(buildHtmlDat() );
    
}


void CustomLabel::setIsActivated(bool isActivated)
{
    if(isActivated)
    {
        setIcon(QIcon("src/usar_teleop/operator_ui/res/enabled.png") );
    }
    else
    {
        cout << "not_enabled" << endl;
        setIcon(QIcon("src/usar_teleop/operator_ui/res/not_enabled.png") );
    }
    
    this->isActivated = isActivated;
}


void CustomLabel::setText(const char* text)
{
    textLblPtr->setText(text);
}


void CustomLabel::setTopic(const char* topic)
{
    this->topic = new QString(topic);
}


QString* CustomLabel::getTopic() const
{
    return topic;
}


void CustomLabel::setIcon(QIcon icon)
{
    QPixmap pixmap = icon.pixmap(25, 25);
    iconLblPtr->setPixmap(pixmap);
}


char* CustomLabel::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


CustomLabel::~CustomLabel()
{
    ;
}
