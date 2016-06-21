#include "../include/robot_operator_ui/SplashScreen.h"


SplashScreen::SplashScreen(QApplication* aApp, QWidget* parent) : QSplashScreen(parent), app(aApp)
{
    this->setPixmap(QPixmap("/home/csrobot/catkin_ws/src/usar_teleop/robot_operator_ui/res/splash.png") );
    this->setCursor(Qt::BusyCursor);
    this->showMessage(QObject::tr("Loading..."),
            Qt::AlignCenter,
            Qt::red);
    
    
    progressBarPtr = new QProgressBar(this);
    progressBarPtr->move(0, 280);
    progressBarPtr->setMinimum(0);
    progressBarPtr->setMaximum(100);
    progressBarPtr->setFixedWidth(355);
    
    QObject::connect(this, SIGNAL(updateProgressBarSig(int )), this, SLOT(incProgressBar(int ) ) );
    
    //updateProgressBar();
    
}


void SplashScreen::incProgressBar(int addThisNum)
{
    cout << "@ incProgressBar(...)" << endl;
    progressBarPtr->setValue(progressBarPtr->value() + addThisNum);
    progressBarPtr->update();
}


void SplashScreen::drawContents(QPainter* painter)
{
    //progressBarPtr->setValue(0);
    //progressBarPtr->update();
}


void SplashScreen::spin()
{
    for(size_t i = 0; i < 100; i++)
    {
        QTime t = QTime::currentTime();
        t = t.addMSecs(20);
        while(t > QTime::currentTime() ) { }
        cout << "emitting message" << endl;
        emit updateProgressBarSig(1);
    }
    
}


SplashScreen::~SplashScreen()
{
    ;
}
