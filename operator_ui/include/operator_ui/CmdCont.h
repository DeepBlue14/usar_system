/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   CmdCont.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 2, 2016, 11:34 PM
 * Last Modified: 3/25/2016
 */

#ifndef CMD_CONTAINER_H
#define CMD_CONTAINER_H

#include <QString>
#include <QVector>

#include "OptionCont.h"

class CmdCont
{
    public:
        /**
         * Constructor.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        CmdCont();
        
        /**
         * Mutator.
         * @see #descStrPtr
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: Member variable descStrPtr is set.<b></dd>
         */
        void setDescStrPtr(QString* descStrPtr);
        
        /**
         * Accessor.
         * @see #pri
         *
         * <dt><b>Pre: <b></dd>
         * <dt><b>Post: <b></dd>
         *
         * @return descStrPtr
         */
        QString* getDescStrPtr() const;
        
        /**
         * Mutator.
         * @see #pri 
         *
         * <dt><b>Pre: <b></dd>
         * <dt><b>Post: <b></dd>
         */
        void setPriority(int pri);
        
        /**
         * Accessor
         * @see pri
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: <b></dd>
         *
         * @return pri
         */
        int getPriority() const;
        
        /**
         * Mutator.
         * @see #cmd
         *
         * <dt><b>Pre: None<b></dd>
         * <dt><b>Post: <b></dd>
         */
        void setCmd(jct::Cmd cmd);
        
        /**
         * Accessor
         * @see #cmd
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: <b></dd>
         *
         * @return cmd
         */
        jct::Cmd getCmd() const;
        
        /**
         * Gets the name of a cmd comand.
         *
         * <dt><b>Pre: <b></dd>
         * <dt><b>Post: <b></dd>
         *
         * @return The actual name command enumeration type.
         */
        const char* getCmdAsStr() const;
        
        /**
         * Mutator.
         * @see #defaultJoy
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: <b></dd>
         */
        void setDefaultJoy(jct::Joy defaultJoy);
        
        /**
         * Accessor.
         * @see #defaultJoy
         *
         * <dt><b>Pre: <b></dd>
         * <dt><b>Post: <b></dd>
         *
         * @return defaultJoy
         */
        jct::Joy getDefaultJoy() const;
        
        /**
         * Finds the name of the specified enumeration type.
         *
         * <dt><b>Pre: <b></dd>
         * <dt><b>Post: <b></dd>
         *
         * @return the name of the enum
         */
        const char* getDefaultJoyAsStr() const;
        
        /**
         * Mutator.
         * @see #optionVecPtr
         *
         * <dt><b>Pre: <b></dd>
         * <dt><b>Post: <b></dd>
         */
        void setOptionVecPtr(QVector<OptionCont*>* optionVecPtr);
        
        /**
         * Accessor
         *
         * <dt><b>Pre: <b></dd>
         * <dt><b>Post: <b></dd>
         *
         * @return optionVecPtr
         */
        QVector<OptionCont*>* getOptionVecPtr() const;
        
        /**
         * Paassthrough layer to add a OptionCont* to the vector optionVecPtr
         *
         * <dt><b>Pre: <b></dd>
         * <dt><b>Post: <b></dd>
         */
        void push_back(OptionCont* optionContPtr);
        
        /**
         * Classic Java-style toString() method.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         * @return Data relevent to this class.
         */
        char* toString();
        
        /**
         * Destructor.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: Deletes all member variables.<b></dd>
         */
        ~CmdCont();
        
    private:
        jct::Cmd name;
        QString* desc;
        int pri;
        jct::Joy defaultJoy;
        QVector<OptionCont*>* optionVecPtr;
        
        
};

#endif /*  CMD_CONTAINER_H */
