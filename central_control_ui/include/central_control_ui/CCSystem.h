/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   CCSystem.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 25, 2016, 2:17 PM
 * Last Modified: 3/25/2016
 */

#ifndef CC_SYSTEM_H
#define CC_SYSTEM_H

#include <QApplication>
#include <QDesktopWidget>
#include <QRect>

namespace ccs
{
    extern QRect* screenSize;
    
    /**
     *
     *
     * <dt><b>Pre: None.<b></dd>
     * <dt><b>Post: None.<b></dd>
     */
    extern void computeScreenSize();
}

#endif /* CC_SYSTEM_H */
