/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/operator_ui/CmdCont.h"

CmdCont::CmdCont()
{
    desc = new QString("null");
    optionVecPtr = new QVector<OptionCont*>();
}


void CmdCont::setDescStrPtr(QString* descStrPtr)
{
    this->desc = descStrPtr;
}


QString* CmdCont::getDescStrPtr() const
{
    return desc;
}


void CmdCont::setPriority(int pri)
{
    this->pri = pri;
}


int CmdCont::getPriority() const
{
    return pri;
}


void CmdCont::setCmd(jct::Cmd cmd)
{
    this->name = cmd;
}


jct::Cmd CmdCont::getCmd() const
{
    return name;
}


const char* CmdCont::getCmdAsStr() const
{
    return jct::getCmdAsStr(name);
}


void CmdCont::setDefaultJoy(jct::Joy defaultJoy)
{
    this->defaultJoy = defaultJoy;
}


jct::Joy CmdCont::getDefaultJoy() const
{
    return defaultJoy;
}


const char* CmdCont::getDefaultJoyAsStr() const
{
    return jct::getJoyAsStr(defaultJoy);
}


void CmdCont::setOptionVecPtr(QVector<OptionCont*>* optionVecPtr)
{
    this->optionVecPtr = optionVecPtr;
}


QVector<OptionCont*>* CmdCont::getOptionVecPtr() const
{
    return optionVecPtr;
}


void CmdCont::push_back(OptionCont* optionContPtr)
{
    optionVecPtr->push_back(optionContPtr);
}


char* CmdCont::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


CmdCont::~CmdCont()
{
    ;
}
