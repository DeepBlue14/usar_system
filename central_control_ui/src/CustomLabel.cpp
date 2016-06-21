/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/central_control_ui/CustomLabel.h"


CustomLabel::CustomLabel(int index, QWidget * parent, Qt::WindowFlags f ) : QLabel( parent, f )
{
    this->index = index;
    clu = new CusLabelMenu();
    cout << "@CustomLabel::CustomLabel(...); my index is: " << index << endl;
}


CustomLabel::CustomLabel(int index, const QString& text, QWidget* parent, Qt::WindowFlags f ) : QLabel( text, parent, f )
{
    this->index = index;
    cout << "@CustomLabel::CustomLabel(...); my index is: " << index << endl;
}


int CustomLabel::getIndex() const
{
    return index;
}


void CustomLabel::mousePressEvent(QMouseEvent* ev )
{

    
    const QPoint p = ev->pos();
    //cout << "Clicked: (" << p.x() << ", " << p.y() << ")" << endl;
    cout << "Button triggered: " << ev->button() << endl;
    switch(ev->button() )
    {
        case Qt::LeftButton:
            this->setStyleSheet("QFrame { background-color: blue }");
            
            emit mousePressed( p );
            emit iWasClicked(index);
            if(index == -1)
            {
                emit swapUiMode();
            }
            break;
        case Qt::RightButton:
            clu->getMenu()->exec(ev->globalPos() );
            break;
        default:
            cerr << "Invalid option @CustomLabel::mousePressEvent(...) in switch" << endl;
    }


}