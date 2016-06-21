/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/robot_operator_ui/XmlMaster.h"

XmlMaster::XmlMaster()
{
    ;
}


QVector<CmdCont*>* XmlMaster::config(const char* fileName)
{
    cout << "running config(...)" << endl;
    jct::init(); //FIXME: This only needs to be called once.  Should it call itself?
    QFile* file = new QFile(fileName);
    file->open(QFile::ReadOnly);
    QXmlStreamReader xmlReader;
    xmlReader.setDevice(file);
    
    QVector<CmdCont*>* configLstContVec = new QVector<CmdCont*>();
    CmdCont* cmdContPtr;
    OptionCont* optionContPtr;
    QString openingTag;
    
    xmlReader.readNext();
    
    int safety = 0;
    while(!xmlReader.isEndDocument() && safety < 500 )
    {
        if(!xmlReader.isEndElement() )
        {
            openingTag = xmlReader.name().toString();
            if(!openingTag.isEmpty() )
            {
                //cout << "<" << openingTag.toStdString() << ">" << endl;
                if(openingTag == "cmd")
                {
                    //create new ConfigLstContainer...
                    cmdContPtr = new CmdCont();
                    configLstContVec->push_back(cmdContPtr);
                }
                else if(openingTag == "option")
                {
                    //cout << xmlReader.readElementText().toStdString() << endl;
                }
            }
        }
        else
        {
            QString closingTag = xmlReader.name().toString();
            //cout << "</" << closingTag.toStdString() << ">" << endl;
        }
        
        QXmlStreamAttributes attributes = xmlReader.attributes();
        for(size_t i = 0; i < attributes.size(); i++)
        {
            //cout << attributes.at(i).name().toString().toStdString() << "=";
            //cout << "\"" << attributes.at(i).value().toString().toStdString() << "\"" << endl;
            if(openingTag == "cmd" && attributes.at(i).name().toString().toStdString() == "name")
            {
                //cout << "created lst for type: " << attributes.at(i).value().toString().toStdString() << endl;
                cmdContPtr->setCmd(jct::strToCmd(attributes.at(i).value().toString() ));
                cout << "name=" << attributes.at(i).value().toString().toStdString() << endl;
            }
            else if(openingTag == "cmd" && attributes.at(i).name().toString().toStdString() == "des")
            {
                QString* tmp = new QString(attributes.at(i).value().toString() );
                cmdContPtr->setDescStrPtr(tmp);
                cout << "des=" << tmp->toStdString() << endl;
            }
            else if(openingTag == "cmd" && attributes.at(i).name().toString().toStdString() == "pri")
            {
                cmdContPtr->setPriority(attributes.at(i).value().toString().toInt() );
                cout << "pri=" << attributes.at(i).value().toString().toInt() << endl;
            }
            else if(openingTag == "cmd" && attributes.at(i).name().toString().toStdString() == "default")
            {
                //attributes.at(i).value().toString() is the default value
                cmdContPtr->setDefaultJoy(jct::strToJoy(attributes.at(i).value().toString() ) );
                cout << "default=" << attributes.at(i).value().toString().toStdString() << endl;
            }
            else if(openingTag == "option" && attributes.at(i).name().toString().toStdString() == "enum")
            {
                optionContPtr = new OptionCont();
                optionContPtr->setJoy(jct::strToJoy(attributes.at(i).value().toString() ) );
                cout << "option enum=" << attributes.at(i).value().toString().toStdString() << endl;
            }
            else if(openingTag == "option" && attributes.at(i).name().toString().toStdString() == "des")
            {
                //configLstContPtr->getStrLstPtr()->append(attributes.at(i).value().toString() );
                optionContPtr->setDesc(new QString(attributes.at(i).value().toString()) );
                cmdContPtr->push_back(optionContPtr);
                cout << "option des=" << attributes.at(i).value().toString().toStdString() << endl;
            }
            else
            {
                //cout << "FAILED: (openingTag: " << openingTag.toStdString() << ", value: " << attributes.at(i).value().toString().toStdString() << ")" << endl;
            }
        }
        
        
        xmlReader.readNext();
        
        safety++;
    }
    
    
    return configLstContVec;
}


void XmlMaster::sort(QString str)
{
    ;
}


void XmlMaster::loadFile(QFile* filePtr)
{
    QFile* file = new QFile("src/usar_teleop/robot_operator_ui/res/test.xml");
    file->open(QFile::ReadOnly);
    QXmlStreamReader xmlReader;
    xmlReader.setDevice(file);
    
    xmlReader.readNext();
    
    int safety = 0;
    while(!xmlReader.isEndDocument() && safety < 50 )
    {
        
     
        if(!xmlReader.isEndElement() )
        {
            QString openingTag = xmlReader.name().toString();
            if(!openingTag.isEmpty() )
            {
                cout << "<" << openingTag.toStdString() << ">" << endl;
                if(openingTag == "option")
                {
                    cout << xmlReader.readElementText().toStdString() << endl;
                }
            }
        }
        else
        {
            QString closingTag = xmlReader.name().toString();
            cout << "</" << closingTag.toStdString() << ">" << endl;
        }
        
        QXmlStreamAttributes attributes = xmlReader.attributes();
        for(size_t i = 0; i < attributes.size(); i++)
        {
            cout << attributes.at(i).name().toString().toStdString() << "=";
            cout << "\"" << attributes.at(i).value().toString().toStdString() << "\"" << endl;
        }
        
        
        xmlReader.readNext();
        
        safety++;
    }
    
    
}


void XmlMaster::printXmlFile(QFile* filePtr)
{
    
}


void XmlMaster::printDat(QVector<CmdCont*>* configLstContVec)
{
    cout << "\n-  -  -  -  -  -  -  -  -  -  -  -  -\n";
    for(size_t i = 0; i < configLstContVec->size(); i++)
    {
        cout << "cmd=" << configLstContVec->at(i)->getCmdAsStr() << endl;
        cout << "des=" << configLstContVec->at(i)->getDescStrPtr()->toStdString() << endl;
        cout << "pri=" <<  configLstContVec->at(i)->getPriority() << endl;
        cout << "default=" <<  configLstContVec->at(i)->getDefaultJoyAsStr() << endl;
        
        for(size_t j = 0; j < configLstContVec->at(i)->getOptionVecPtr()->size(); j++)
        {
            cout << "    joy=" << configLstContVec->at(i)->getOptionVecPtr()->at(j)->getJoy() << endl;
            cout << "    des=" << configLstContVec->at(i)->getOptionVecPtr()->at(j)->getDesc()->toStdString() << endl;
        }
    }
}


void XmlMaster::insertAfterLastOccurrence(QFile* filePtr, QString* occurrenceOfStrPtr, QString* insertionStrPtr)
{
    ;
}


XmlMaster::~XmlMaster()
{
    ;
}
