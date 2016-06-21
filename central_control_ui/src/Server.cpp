/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */


#include "../include/central_control_ui/Server.h"

QT_USE_NAMESPACE

Server::Server(QObject* parent) : QObject(parent), m_pWebSocketServer(Q_NULLPTR), m_clients()
{
    pub = new ros::Publisher();
}


void Server::setup(quint16 port)
{
    m_pWebSocketServer = new QWebSocketServer(QStringLiteral("Chat Server"),
                                              QWebSocketServer::NonSecureMode,
                                              this);
    if(m_pWebSocketServer->listen(QHostAddress::Any, port) )
    {
        qDebug() << "Chat Server listening on port" << port;
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                this, &Server::onNewConnection);
    }
    
    masterGui = new MasterGui();
    masterGui->show();
    
    connect(this, SIGNAL(acceptedNewConnection_1(int ) ), masterGui, SLOT(test_slot_2() ) );
}


void Server::messageBridge(const geometry_msgs::TwistConstPtr& msg)
{
    //convert ROS Twist.linear.x --> QString
    qtMsg = QString::number(msg->linear.x);
    
    //FIXME: ???should it make one falseprince socket in the constructor; or create one for each subscriber???
    QWebSocket falsePrince;
    connect(&falsePrince, &QWebSocket::textMessageReceived, this, &Server::processMessage);
    
    //if(qtMsg.compare("Arise, my robot army!") != 0 )
    {
        std::cout << "about to emit signal" << std::endl;
        emit falsePrince.textMessageReceived(qtMsg);
    }
    
}


void Server::onNewConnection()
{
	std::cout << "@ Server::onNewConnection()" << std::endl;
    QWebSocket* pSocket = m_pWebSocketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::textMessageReceived, this, &Server::processMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &Server::socketDisconnected);

    m_clients << pSocket;
}

void Server::processMessage(QString message)
{
	std::cout << "@ Server::processMessage(...)" << std::endl;
	std::cout << "I heard: " << message.toStdString() << std::endl;
	
	//-----
	if(message == "OBSERVER")
	{
	    emit acceptedNewConnection_1(1);
	}
	//-----
	
    QWebSocket* pSender = qobject_cast<QWebSocket*>(sender() );
    Q_FOREACH (QWebSocket* pClient, m_clients)
    {
        if(pClient != pSender) //don't echo message back to sender
        {
            std::cout << "(Server) sending message: \"" << message.toStdString() << std::endl;
            pClient->sendTextMessage(message);
        }
    }
}

void Server::socketDisconnected()
{
    QWebSocket* pClient = qobject_cast<QWebSocket*>(sender() );
    if(pClient)
    {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}


ros::Publisher* Server::getPublisher() const
{
    return pub;
}


Server::~Server()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end() );
}
