/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/trajectory_rgbd/Scope.h"

Scope::Scope()
{
    //frameCount = 0;
    //distCount = 0;
    color = new Scalar(0, 0, 255);
    pub = new image_transport::Publisher();
}


void Scope::imageCallback(const sensor_msgs::ImageConstPtr& input)
{
    /*if(distCount < 30 || frameCount < 30)
    {
        frameCount++;
        return;
    }*/
    
    cv::Mat cvImage;
    
    try
    {
        cv_ptr = cv_bridge::toCvCopy(input, sensor_msgs::image_encodings::BGR8);
    }
    catch(cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what() );
    }
    
    this->cvImage = cvImage = cv_ptr->image;
    drawTarget();
}


void Scope::distCallback(const std_msgs::BoolConstPtr& input)
{
    /*if(distCount < 30 || frameCount < 30)
    {
        distCount++;
        return;
    }*/

    if(input->data == true)
    {
        color = new Scalar(0, 255, 0);
    }
    else
    {
        color = new Scalar(0, 0, 255);
    }
}


void Scope::drawTarget()
{
    
    circle(cvImage, Point(320, 240), 20, *color, 2);
	//draw cross hair:
	line(cvImage, Point(0, 240), Point(640, 240), *color, 1);
	line(cvImage, Point(320, 0), Point(320, 480), *color, 1);

    line(cvImage, Point(280, 240), Point(360, 240), *color, 2);
	line(cvImage, Point(320, 200), Point(320, 280), *color, 2);

    
    imshow("Target", cvImage);
    waitKey(3);
    
    //cv_bridge::CvImagePtr cv_ptr;
    cv_ptr->image = cvImage;
    pub->publish(cv_ptr->toImageMsg() );
}


image_transport::Publisher* Scope::getPublisher() const
{
    return pub;
}


char* Scope::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


Scope::~Scope()
{
    ;
}
