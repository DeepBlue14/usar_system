/* 
 * File:   SplashScreen.h
 * Module: Unaffiliated
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description:
 * 
 * References: http://stackoverflow.com/questions/14230265/what-is-the-proper-way-to-set-qprogressbar-to-update-from-the-logic-layer
 *
 * Created on May 18, 2015, 3:16 PM
 */

#ifndef SPLASH_SCREEN_H
#define	SPLASH_SCREEN_H

#include <QSplashScreen>
#include <QStyle>
#include <QStyleOptionProgressBar>
#include <QPainter>
#include <QProgressBar>
#include <QDateTime>

#include <iostream>


using namespace std;

class SplashScreen : public QSplashScreen
{
    Q_OBJECT
    
    private:
        QApplication* app;
        QProgressBar* progressBarPtr;
 
    public slots:
        void incProgressBar(int addThisNum);
        
    public:
        /**
         * Constructor.
         * 
         * @param parent reference to parent type.
         */
        explicit SplashScreen(QApplication* app, QWidget* parent = 0);
        
        void spin();
        
        virtual void drawContents(QPainter* painter);
        
        /**
         * 
         */
        ~SplashScreen();
        
    signals:
        void updateProgressBarSig(int num);
};

#endif	/* SPLASH_SCREEN_H */
