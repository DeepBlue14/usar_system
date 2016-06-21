/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/operator_ui/OptionCont.h"


OptionCont::OptionCont()
{
    desc = new QString("null");
}


void OptionCont::setJoy(jct::Joy joy)
{
    this->joy = joy;
}


jct::Joy OptionCont::getJoy() const
{
    return joy;
}


void OptionCont::setDesc(QString* desc)
{
    this->desc = desc;
}


QString* OptionCont::getDesc() const
{
    return desc;
}


char* OptionCont::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


OptionCont::~OptionCont()
{
    delete desc;
}
