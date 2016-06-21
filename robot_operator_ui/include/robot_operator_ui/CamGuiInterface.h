/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CamGuiInterface.h
 * Author: James
 *
 * Created on March 11, 2016, 4:51 PM
 */

#ifndef CAMGUIINTERFACE_H
#define CAMGUIINTERFACE_H

#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QString>
#include <QGridLayout>

class CamWidget : public QWidget
{
    Q_OBJECT
            
    public:
        explicit CamWidget(QWidget* parent = 0);
        char* toString();
        virtual ~CamWidget();
        
    private:
        QImage* imagePtr;
        QLabel* imageContainerLblPtr;
        QGridLayout* outerLayout;
};

#endif /* CAMGUIINTERFACE_H */
