/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   Server.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 8, 2016, 6:12 PM
 * Last Modified: 3/25/2016
 */

#ifndef SERVER_H
#define SERVER_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QWebSocket>
#include <QtCore/QDebug>

#include <iostream>

#include "CCTypes.h"
#include "MasterGui.h"

using namespace std;

class Server : public QObject
{
    Q_OBJECT
    
    signals:
        void acceptedNewConnection_1(int type); //TODO: use enum.  For now, operator = 0, observer = 1
    
    public:
        explicit Server(QObject* parent = Q_NULLPTR);
        void setup(quint16 port);
        void messageBridge(const geometry_msgs::TwistConstPtr& msg);
        ros::Publisher* getPublisher() const;
        virtual ~Server();

    private Q_SLOTS:
        void onNewConnection();
        void processMessage(QString message);
        void socketDisconnected();

    private:
        QString qtMsg;
        QWebSocketServer* m_pWebSocketServer;
        QList<QWebSocket*> m_clients;
        ros::Publisher* pub;
        MasterGui* masterGui;
};

#endif /* SERVER_H */
