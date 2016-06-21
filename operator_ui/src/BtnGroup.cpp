#include "../include/operator_ui/BtnGroup.h"

BtnGroup::BtnGroup(QWidget* parent) : QWidget(parent)
{
    okBtn = new QPushButton("OK");
    cancelBtn = new QPushButton("Cancel");
    applyBtn = new QPushButton("Apply");
    helpBtn = new QPushButton("Help");
    
    outerLayout = new QGridLayout();
    outerLayout->addWidget(okBtn, 0, 0);
    outerLayout->addWidget(cancelBtn, 0, 1);
    outerLayout->addWidget(applyBtn, 0, 2);
    outerLayout->addWidget(helpBtn, 0, 3);
    
    this->setLayout(outerLayout);
}


QPushButton* BtnGroup::getOkBtn() const
{
    return okBtn;
}


QPushButton* BtnGroup::getCancelBtn() const
{
    return cancelBtn;
}


QPushButton* BtnGroup::getApplyBtn() const
{
    return applyBtn;
}


QPushButton* BtnGroup::getHelpBtn() const
{
    return helpBtn;
}


char* BtnGroup::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


BtnGroup::~BtnGroup()
{
    ;
}
