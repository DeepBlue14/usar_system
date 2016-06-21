#include "../include/operator_ui/OpConfigGui.h"

OpConfigGui::OpConfigGui(QScrollArea* parent) : QScrollArea(parent)
{
    configJoyGui = new ConfigJoyGui();
    inRunGui = new InRunGui();
    
    loadPreRunOp();
    //loadInRunOp();
    
    //-----------------------------------------------------
    /*
    QFile file("res/InGame.css");
    file.open(QFile::ReadOnly);
    QString styleSheetStr = QLatin1String(file.readAll() );
    this->setStyleSheet(styleSheetStr);
    this->ensurePolished();
    */
    //-----------------------------------------------------
    
    connect(configJoyGui, SIGNAL(closeUi() ), this, SLOT(handleCloseUiEvt() ) );
    
    QRect rect = QApplication::desktop()->screenGeometry();
    this->setGeometry( (rect.width()/2)-(540/2), (rect.height()/2)-(240/2), 540, 240);
    this->resize(685, (rect.height()/2)-(240/2));
}


void OpConfigGui::loadPreRunOp()
{
    this->setWidget(configJoyGui);
}


void OpConfigGui::unloadPreRunOp()
{
    configJoyGui->setVisible(false);
    configJoyGui->setEnabled(false);
    
}


void OpConfigGui::loadInRunOp()
{
    this->setWidget(inRunGui);
    inRunGui->setVisible(true);
    inRunGui->setEnabled(true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    inRunGui->setAttribute(Qt::WA_TranslucentBackground);
    inRunGui->getFileTypeLwPtr()->setAttribute(Qt::WA_TranslucentBackground);
    inRunGui->getLangsLwPtr()->setAttribute(Qt::WA_TranslucentBackground);
    
    
    //this->setWindowOpacity(0.5); // This works!
}


void OpConfigGui::unloadInRunOp()
{
    inRunGui->setVisible(false);
    inRunGui->setEnabled(false);
}


void OpConfigGui::handleCloseUiEvt()
{
    cout << "@OpConfigGui::handleCloseUiEvt()" << endl;
    this->close();
}


char* OpConfigGui::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


OpConfigGui::~OpConfigGui()
{
    ;
}
