/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/robot_operator_ui/ConfigLstContainer.h"

ConfigLstContainer::ConfigLstContainer()
{
    descStrPtr = new QString("null");
    strLstPtr = new QStringList();
}


void ConfigLstContainer::setDescStrPtr(QString* descStrPtr)
{
    this->descStrPtr = descStrPtr;
}


QString* ConfigLstContainer::getDescStrPtr() const
{
    return descStrPtr;
}


void ConfigLstContainer::setStrLstPtr(QStringList* strLstPtr)
{
    this->strLstPtr = strLstPtr;
}


QStringList* ConfigLstContainer::getStrLstPtr() const
{
    return strLstPtr;
}


void ConfigLstContainer::setCmd(jct::Cmd cmd)
{
    this->cmd = cmd;
}


jct::Cmd ConfigLstContainer::getCmd() const
{
    return cmd;
}


const char* ConfigLstContainer::getCmdAsStr() const
{
    return jct::getCmdAsStr(cmd);
}


char* ConfigLstContainer::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


ConfigLstContainer::~ConfigLstContainer()
{
    ;
}        
