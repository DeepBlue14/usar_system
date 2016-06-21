/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   CustomLabel.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 22, 2016, 6:05 PM
 * Last Modified: 3/25/2016
 */

#ifndef CUSTOM_LABEL_H
#define CUSTOM_LABEL_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QIcon>
#include <QHBoxLayout>

#include <iostream>

using namespace std;

class CustomLabel : public QWidget
{
    Q_OBJECT
            
    public:
        explicit CustomLabel(const char* name, const char* topic, QWidget* parent = 0);
        void setIsSelected(bool isSelected);
        void setIsActivated(bool isActivated);
        void setText(const char* name);
        //text()
        void setTopic(const char* topic);
        QString* getTopic() const;
        void setIcon(QIcon icon);
        char* toString();
        virtual ~CustomLabel();

        
    private:
        QString buildHtmlDat();
        
        bool isSelected;
        bool isActivated;
        QString* name;
        QString* topic;
        
        QLabel* iconLblPtr;
        QLabel* textLblPtr;
        QHBoxLayout* outerLayout;
};

#endif /* CUSTOM_LABEL_H */
