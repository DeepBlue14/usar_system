/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   XmlMaster.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: XML parser for the joy --> command configurations.
 * 
 * Use QXmlStreamReader instead of dom stuff
 * Ref: http://doc.qt.io/qt-4.8/qxmlstreamreader.html#isEndElement
 *
 * Created on April 30, 2016, 11:37 PM
 * Last Modified: 3/30/2016
 */

#ifndef XML_MASTER_H
#define	XML_MASTER_H

#include <QWidget>
#include <QtXml>
#include <QXmlStreamReader>
#include <QFile>
#include <QString>

#include <iostream>

#include "CmdCont.h"
#include "JoyCmdTypes.h"

using namespace std;

class XmlMaster
{
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        XmlMaster();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        QVector<CmdCont*>* config(const char* fileName);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void loadFile(QFile* filePtr);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void printXmlFile(QFile* filePtr);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void insertAfterLastOccurrence(QFile* filePtr, QString* occurrenceOfStrPtr, QString* insertionStrPtr);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void printDat(QVector<CmdCont*>* configLstContVec);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        ~XmlMaster();
        
    private:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void sort(QString str);
        
        ;
};

#endif	/* XML_MASTER_H */
