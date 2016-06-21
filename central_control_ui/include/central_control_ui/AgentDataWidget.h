/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   AgentDataWidget.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description:
 *
 * Created on March 21, 2016, 7:20 PM
 * Last Modified: 3/25/2016
 */

#ifndef AGENT_DATA_WIDGET_H
#define AGENT_DATA_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class AgentDataWidget : public QWidget
{
    Q_OBJECT
            
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit AgentDataWidget(QWidget* parent = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        char* toString();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        virtual ~AgentDataWidget();
        
    private:
        QLabel* nameLbl;
        QLabel* ipAddrLbl;
        QPushButton* overrideBtn;
        QPushButton* eStopBtn;
        QGridLayout* outerLayout;
};

#endif /* AGENTDATAWIDGET_H */
