/* 
 * File:   MasterGui.h
 * Author: james
 * 
 * Notes: zoom isn't quite done yet.
 *        linear movement is relative to the initial orientation of the image
 *
 * Created on April 16, 2016, 7:59 PM
 */

#ifndef HRI_MAP_H
#define HRI_MAP_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

#include <QWidget>
#include <QRect>
#include <QPixmap>
#include <QKeyEvent>
#include <QBrush>
#include <QPaintEvent>
#include <QLabel>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include <QGridLayout>
#include <QString>

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

class HriMap : public QWidget
{
    Q_OBJECT
            
    public:
        enum Shape
        {
            RECTANGLE,
            CIRCLE
        };
        
        explicit HriMap(QWidget* parent = 0);
        
        void callback(const geometry_msgs::TwistConstPtr& msg);
        
        void rotateCounterClockwise();
        void rotateClockwise();
        void shiftLeft();
        void shiftRight();
        void shiftUp();
        void shiftDown();
        void zoomIn();
        void zoomOut();
        
        char* toString();
        virtual ~HriMap();
        
    protected:
        void paintEvent(QPaintEvent* event);
    
    private:
        int widgetOffsetX;
        int widgetOffsetY;
        int degrees;
        int x;
        int y;
        int width;
        int height;
        
        QImage image;
        QGridLayout* outerLayout;
        geometry_msgs::Twist mov;
        
        ros::NodeHandle nh;
        ros::Subscriber sub;
};

#endif /* HRI_MAP_H */
