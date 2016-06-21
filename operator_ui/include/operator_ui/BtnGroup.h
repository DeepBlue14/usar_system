/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   BtnGroup.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: Container class for the panel containing
 *                   OK/Cancel/Apply/Help buttons.
 *
 * Created on March 2, 2016, 11:34 PM
 * Last Modified: 3/28/2016
 */

#ifndef BTN_GROUP_H
#define BTN_GROUP_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class BtnGroup : public QWidget
{
    Q_OBJECT
            
    public:
        /**
         * Constructor.
         * 
         * <dt><b>Pre:<b></dd> None
         * <dt><b>Post:<b></dd> Member variables of this class are instantiated.
         *
         * @param parent Parent type.
         */
        explicit BtnGroup(QWidget* parent = 0);
        
        /**
         * Accessor.
         * 
         * <dt><b>Pre:<b></dd> None
         * <dt><b>Post:<b></dd> None
         *
         * @return OK button
         */
        QPushButton* getOkBtn() const;
        
        /**
         * Accessor.
         * 
         * <dt><b>Pre:<b></dd> None
         * <dt><b>Post:<b></dd> None
         *
         * @return Cancel button
         */
        QPushButton* getCancelBtn() const;
        
        /**
         * Accessor.
         * 
         * <dt><b>Pre:<b></dd> None
         * <dt><b>Post:<b></dd> None
         *
         * @return Apply button
         */
        QPushButton* getApplyBtn() const;
        
        /**
         * Accessor.
         * 
         * <dt><b>Pre:<b></dd> None
         * <dt><b>Post:<b></dd> None
         *
         * @return Help button.
         */
        QPushButton* getHelpBtn() const;
        
        /**
         * Java-style toString() method.
         * 
         * <dt><b>Pre:<b></dd> None
         * <dt><b>Post:<b></dd> None
         *
         * @return Relevent data of this object
         */
        char* toString();
        
        /**
         * Destructor.
         * 
         * <dt><b>Pre:<b></dd> None
         * <dt><b>Post:<b></dd> Member variables contained within this class are deleted.
         */
        virtual ~BtnGroup();
        
    private:
        QPushButton* okBtn; /** OK button. */
        QPushButton* cancelBtn; /** Cancel button. */
        QPushButton* applyBtn; /** Apply button. */
        QPushButton* helpBtn; /** Help button */
        QGridLayout* outerLayout; /**  Outermost layout for this class. */
};

#endif /* BTN_GROUP_H */
