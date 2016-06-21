/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/operator_ui/JoyUiBridge.h"

JoyUiBridge::JoyUiBridge()
{
    sub = nh.subscribe<std_msgs::Int32>("/joy/topic", 1, &JoyUiBridge::topicCallback, this);
    armSysSub = nh.subscribe<std_msgs::Bool>("/joy/enable", 1, &JoyUiBridge::armSysCallback, this);
}
     
        
void JoyUiBridge::topicCallback(std_msgs::Int32 msg)
{
    //cout << "@JoyUiBridge::topicCallback(...); emitting signal" << endl;
    emit swapTopic(static_cast<int>(msg.data) );
}


void JoyUiBridge::armSysCallback(std_msgs::Bool msg)
{
    emit armSys(static_cast<bool>(msg.data) );
}


void JoyUiBridge::openOptCallback(std_msgs::Bool msg)
{
    emit openOpt(static_cast<bool>(msg.data) );
}


char* JoyUiBridge::toString()
{
    ;
}


JoyUiBridge::~JoyUiBridge()
{
    ;
}
