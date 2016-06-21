/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/operator_ui/JoyCmdTypes.h"

namespace jct
{
    QStringList* cmdStrLstPtr = new QStringList();
    
    QStringList* joyStrLstPtr = new QStringList();
    
    
    void init()
    {
         *cmdStrLstPtr << "ROBOT_MOV"             << "NERF_MOV"
                       << "SWAP_TOPIC"            << "FIRE_NERF" 
                       << "TOGGLE_UI_MODE"        << "TOGGLE_VOICE"
                       << "E_STOP"                << "TOGGLE_UI_FOCUS"
                       << "TOGGLE_AUTONOMY"       << "TOGGLE_NERF";
                     
        *joyStrLstPtr  << "AXIS_LEFT"             << "AXIS_RIGHT"
                       << "AXIS_LEFT_RIGHT"       << "FACE_UP"
                       << "FACE_DOWN"             << "FACE_LEFT"
                       << "FACE_RIGHT"            << "FACE_UP_DOWN"
                       << "FACE_UP_LEFT_RIGHT"    << "DPAD_UP"
                       << "DPAD_DOWN"             << "DPAD_LEFT"
                       << "DPAD_RIGHT"            << "DPAD_UP_DOWN"
                       << "DPAD_UP_LEFT_RIGHT"    << "BACK"
                       << "FORWARD"               << "LEFT_SHOULDER_TOP"
                       << "LEFT_SHOULDER_BOTTOM"  << "RIGHT_SHOULDER_TOP"
                       << "RIGHT_SHOULDER_BOTTOM" << "DISABLED"
                       << "NA";
    }
    
    
    char* getCmdAsStr(Cmd cmd)
    {
        char* str;
        
        switch(cmd)
        {
            case ROBOT_MOV:
                str = const_cast<char*>("ROBOT_MOV");
                break;
            case NERF_MOV:
                str = const_cast<char*>("NERF_MOV");
                break;
            case SWAP_TOPIC:
                str = const_cast<char*>("SWAP_TOPIC");
                break;
            case FIRE_NERF:
                str = const_cast<char*>("FIRE_NERF");
                break;
            case TOGGLE_UI_MODE:
                str = const_cast<char*>("TOGGLE_UI_MODE");
                break;
            case TOGGLE_VOICE:
                str = const_cast<char*>("TOGGLE_VOICE");
                break;
            case E_STOP:
                str = const_cast<char*>("E_STOP");
                break;
            case TOGGLE_UI_FOCUS:
                str = const_cast<char*>("TOGGLE_UI_FOCUS");
                break;
            case TOGGLE_AUTONOMY:
                str = const_cast<char*>("TOGGLE_AUTONOMY");
                break;
            case TOGGLE_NERF:
                str = const_cast<char*>("TOGGLE_NERF");
                break;
            default:
                str = const_cast<char*>("ERROR @JoyCmdTypes.h");
        }
        
        
        return str;
    }
    
    
    char* getJoyAsStr(Joy joy)
    {
        char* str;
        
        switch(joy)
        {
            case AXIS_LEFT:
                str = const_cast<char*>("AXIS_LEFT");
                break;
            case AXIS_RIGHT:
                str = const_cast<char*>("AXIS_RIGHT");
                break;
            case AXIS_LEFT_RIGHT:
                str = const_cast<char*>("AXIS_LEFT_RIGHT");
                break;
            case FACE_UP:
                str = const_cast<char*>("FACE_UP");
                break;
            case FACE_DOWN:
                str = const_cast<char*>("FACE_DOWN");
                break;
            case FACE_LEFT:
                str = const_cast<char*>("FACE_LEFT");
                break;
            case FACE_RIGHT:
                str = const_cast<char*>("FACE_RIGHT");
                break;
            case FACE_UP_DOWN:
                str = const_cast<char*>("FACE_UP_DOWN");
                break;
            case FACE_UP_LEFT_RIGHT:
                str = const_cast<char*>("FACE_UP_LEFT_RIGHT");
                break;
            case DPAD_UP:
                str = const_cast<char*>("DPAD_UP");
                break;
            case DPAD_DOWN:
                str = const_cast<char*>("DPAD_DOWN");
                break;
            case DPAD_LEFT:
                str = const_cast<char*>("DPAD_LEFT");
                break;
            case DPAD_RIGHT:
                str = const_cast<char*>("DPAD_RIGHT");
                break;
            case DPAD_UP_DOWN:
                str = const_cast<char*>("DPAD_UP_DOWN");
                break;
            case DPAD_UP_LEFT_RIGHT:
                str = const_cast<char*>("DPAD_UP_LEFT_RIGHT");
                break;
            case BACK:
                str = const_cast<char*>("BACK");
                break;
            case FORWARD:
                str = const_cast<char*>("FORWARD");
                break;
            case LEFT_SHOULDER_TOP:
                str = const_cast<char*>("LEFT_SHOULDER_TOP");
                break;
            case LEFT_SHOULDER_BOTTOM:
                str = const_cast<char*>("LEFT_SHOULDER_BOTTOM");
                break;
            case RIGHT_SHOULDER_TOP:
                str = const_cast<char*>("RIGHT_SHOULDER_TOP");
                break;
            case RIGHT_SHOULDER_BOTTOM:
                str = const_cast<char*>("RIGHT_SHOULDER_BOTTOM");
                break;
            case DISABLED:
                str = const_cast<char*>("DISABLED");
                break;
            case NA:
                str = const_cast<char*>("NA");
                break;
            default:
                str = const_cast<char*>("ERROR @JoyCmdTypes.h");
        }
        
        
        return str;
    }
    
    
    Cmd strToCmd(QString str)
    {
        Cmd cmd;
        cout << "@strToCmd(...); number of options: " << cmdStrLstPtr->size() << endl;
        
        for(size_t i = 0; i < cmdStrLstPtr->size(); i++)
        {
            cout << "comparing: " << str.toStdString() << " with: " << cmdStrLstPtr->at(i).toStdString() << endl;
            if(str == cmdStrLstPtr->at(i) )
            {
                cmd = static_cast<Cmd>(i);
            }
        }
        
        
        return cmd;
    }
    
    
    Joy strToJoy(QString str)
    {
        Joy joy;
    
        for(size_t i = 0; i < joyStrLstPtr->size(); i++)
        {
            if(str == joyStrLstPtr->at(i) )
            {
                joy = static_cast<Joy>(i);
            }
        }
        
        return joy;
    }
        


} // END of namespace jct
