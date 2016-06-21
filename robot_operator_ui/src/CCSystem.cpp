/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/robot_operator_ui/CCSystem.h"

namespace ccs
{
    QRect* screenSize;
    
    void computeScreenSize()
    {
        screenSize = new QRect(QApplication::desktop()->availableGeometry() );
    }
    
    
    
    
}
