/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   JoyCmdTypes.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 2, 2016, 11:34 PM
 * Last Modified: 3/25/2016
 */

#ifndef JOY_CMD_TYPES_H
#define JOY_CMD_TYPES_H

#include <QStringList>

#include <iostream>

using namespace std;

namespace jct
{
    enum Cmd
    {
        ROBOT_MOV,
        NERF_MOV,
        SWAP_TOPIC,
        FIRE_NERF,
        TOGGLE_UI_MODE, //window vs tab modes
        TOGGLE_VOICE,
        E_STOP,
        TOGGLE_UI_FOCUS,
        TOGGLE_AUTONOMY,
        TOGGLE_NERF
    };
        
    enum Joy
    {
        AXIS_LEFT,
        AXIS_RIGHT,
        AXIS_LEFT_RIGHT, //e-stop
        FACE_UP,
        FACE_DOWN,
        FACE_LEFT,
        FACE_RIGHT,
        FACE_UP_DOWN,
        FACE_UP_LEFT_RIGHT,
        DPAD_UP,
        DPAD_DOWN,
        DPAD_LEFT,
        DPAD_RIGHT,
        DPAD_UP_DOWN,
        DPAD_UP_LEFT_RIGHT,
        BACK,
        FORWARD,
        LEFT_SHOULDER_TOP,
        LEFT_SHOULDER_BOTTOM,
        RIGHT_SHOULDER_TOP,
        RIGHT_SHOULDER_BOTTOM,
        DISABLED,
        NA
    };
    
    
    extern QStringList* cmdStrLstPtr;
    extern QStringList* joyStrLstPtr;
    
    extern void init();
    extern char* getCmdAsStr(Cmd cmd);
    extern char* getJoyAsStr(Joy joy);
    extern Cmd strToCmd(QString str);
    extern Joy strToJoy(QString str);


}

#endif /* JOY_CMD_TYPES_H */
