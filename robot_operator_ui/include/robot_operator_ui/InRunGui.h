/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   InRunGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description:
 *
 * Created on May 15, 2015, 9:24 AM
 * Last Modified: 
 */

#ifndef IN_RUN_GUI_H
#define	IN_RUN_GUI_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QStringList>
#include <QStringListModel>
#include <QVector>
#include <QListWidget>
#include <QTextEdit>
#include <QGridLayout>

#include <iostream>



using std::cout;
using std::cerr;
using std::endl;

class InRunGui : public QWidget
{
    Q_OBJECT

public:
    /**
     *
     *
     * <dt><b>Pre: None.<b></dd>
     * <dt><b>Post: None.<b></dd>
     */
    explicit InRunGui(QWidget* parent = 0);

    /**
     *
     *
     * <dt><b>Pre: None.<b></dd>
     * <dt><b>Post: None.<b></dd>
     */
    void setLangStrPtr();

    /**
     *
     *
     * <dt><b>Pre: None.<b></dd>
     * <dt><b>Post: None.<b></dd>
     */
    QString* getLangStrPtr();

    /**
     *
     *
     * <dt><b>Pre: None.<b></dd>
     * <dt><b>Post: None.<b></dd>
     */
    void setFileTypeStrPtr();

    /**
     *
     *
     * <dt><b>Pre: None.<b></dd>
     * <dt><b>Post: None.<b></dd>
     */
    QString* getFileTypeStrPtr();
    
    /**
     *
     *
     * <dt><b>Pre: None.<b></dd>
     * <dt><b>Post: None.<b></dd>
     */
    QListWidget* getLangsLwPtr() const;
    
    /**
     *
     *
     * <dt><b>Pre: None.<b></dd>
     * <dt><b>Post: None.<b></dd>
     */
    QListWidget* getFileTypeLwPtr() const;

    /**
     *
     *
     * <dt><b>Pre: None.<b></dd>
     * <dt><b>Post: None.<b></dd>
     */
    void triggerMutators();

    /**
     *
     *
     * <dt><b>Pre: None.<b></dd>
     * <dt><b>Post: None.<b></dd>
     */
    QString* toString();

    /**
     *
     *
     * <dt><b>Pre: None.<b></dd>
     * <dt><b>Post: None.<b></dd>
     */
    virtual ~InRunGui();
    
    
private slots:
    /**
     *
     *
     * <dt><b>Pre: None.<b></dd>
     * <dt><b>Post: None.<b></dd>
     */
    void handleSwapOptionsSlot();
    
    
private:
    QLabel* titlePtr;
    //QStringList* langsStrLstPtr;
    QVector<QListWidgetItem*>* langsStrLstPtr;
    QVector<QListWidgetItem*>* cFileOptLstWidPtrVecPtr;
    QVector<QListWidgetItem*>* cppFileOptLstWidPtrVecPtr;
    QVector<QListWidgetItem*>* pythonFileOptLstWidPtrVecPtr;
    QVector<QListWidgetItem*>* javaFileOptLstWidPtrVecPtr;
    QVector<QListWidgetItem*>* lispFileOptLstWidPtrVecPtr;
    QVector<QVector<QListWidgetItem*>*>* fileTypeStrLstPtrVec;
    QListWidget* langsLwPtr;
    QListWidget* fileTypeLwPtr;

    QGridLayout* outerLayoutPtr;

    QString* langStrPtr;
    QString* fileTypeStrPtr;
};

#endif	/* IN_RUN_GUI_H */
