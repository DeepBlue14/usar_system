/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/central_control_ui/MapWidget.h"


MapWidget::MapWidget(int index, const char* defaultImgStr, QWidget* parent) : QWidget(parent)
{
    
    imagePtr = new QImage();
    imagePtr->load(defaultImgStr);
    //---------------------------------------------
    ccs::computeScreenSize();
    resizeImage();
    //cout << "size: (" << ccs::screenSize->width() << ", " << ccs::screenSize->height() << ")" << endl;
    //---------------------------------------------
    imageContainerLblPtr = new CustomLabel(index);
    imageContainerLblPtr->setPixmap(QPixmap::fromImage(*imagePtr) );
    
    outerLayout = new QGridLayout();
    outerLayout->addWidget(imageContainerLblPtr);
    

    
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
    imagePtr = new QImage(imagePtr->scaled(imagePtr->width()*ccs::screenSize->width()/1700,
                          imagePtr->height()*ccs::screenSize->height()/170,
                          Qt::KeepAspectRatio) );
}


void MapWidget::setMap(const char* mapImagePath, bool resize)
{
    imagePtr = new QImage();
    imagePtr->load(mapImagePath);
    ccs::computeScreenSize();
    resizeImage();
    imageContainerLblPtr->setPixmap(QPixmap::fromImage(*imagePtr) );
}


CustomLabel* MapWidget::getLabel() const
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
