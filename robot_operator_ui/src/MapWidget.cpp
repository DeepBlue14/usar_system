/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/robot_operator_ui/MapWidget.h"


MapWidget::MapWidget(const char* defaultImgStr, QWidget* parent) : QWidget(parent)
{
    imagePtr = new QImage();
    imagePtr->load(defaultImgStr);
    
    ccs::computeScreenSize();
    resizeImage();
    
    imageContainerLblPtr = new QLabel();
    imageContainerLblPtr->setPixmap(QPixmap::fromImage(*imagePtr) );
    
    
    outerLayout = new QGridLayout();
    outerLayout->addWidget(imageContainerLblPtr, 0, 0, Qt::AlignCenter);
    
    this->setLayout(outerLayout);
}


void MapWidget::addBorder()
{
    imageContainerLblPtr->setFrameStyle(QFrame::Panel | QFrame::Raised);
    imageContainerLblPtr->setLineWidth(5);
}


void MapWidget::focus()
{
    imageContainerLblPtr->setStyleSheet("QFrame { background-color: blue }");
}


void MapWidget::unfocus()
{
    imageContainerLblPtr->setStyleSheet("QFrame { background-color: white }");
}


void MapWidget::resizeImage()
{
    imagePtr = new QImage(imagePtr->scaled(imagePtr->width()*ccs::screenSize->width()/2500,
                          imagePtr->height()*ccs::screenSize->height()/250,
                          Qt::KeepAspectRatio) );
}


QLabel* MapWidget::getLabel() const
{
    return imageContainerLblPtr;
}


char* MapWidget::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


MapWidget::~MapWidget()
{
    ;
}
