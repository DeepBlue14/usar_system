/*
 * File: ColorDetection.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This node subscribes to /camera/rgb/image_rect_color, and 
 *                   dynamically allows the user to filter the image by rgb
 *                   values.
 *
 *
 * Created May 26, 2015 at 6:00pm
 */

#ifndef COLOR_DETECTION_H
#define COLOR_DETECTION_H

#include <ros/ros.h>
#include <ros/console.h>

#include <sensor_msgs/Image.h>
#include <sensor_msgs/PointCloud2.h>
#include <dynamic_reconfigure/server.h>
#include <target_aquisition/ImageParamsConfig.h>


#include <opencv/cv.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using namespace ros;
using namespace cv;
using namespace std;

class ColorDetection
{
    private:
	    static bool activateGuiBool;
	    
	    static int redMinInt;
	    static int greenMinInt;
	    static int blueMinInt;
        static int redMaxInt;
        static int greenMaxInt;
        static int blueMaxInt;

        static int hMinInt;
        static int sMinInt;
        static int vMinInt;
        static int hMaxInt;
        static int sMaxInt;
        static int vMaxInt;

        vector<int> validXVec;
        vector<int> validYVec;
        int minX;
        int minY;
        int maxX;
        int maxY;
        
        Mat m_image;

	    Publisher* pub;

    public:
        /**
         * Constructor initializes the constructor.
         */
	    ColorDetection();
	    
	    /**
	     * 
	     */
	    void callback(const sensor_msgs::ImageConstPtr& input);
	    
	    /**
	     *
	     */
	    void findColor();
	    void checkSize();
	    void prettyPrint();
	    void setActivateGuiBool(bool activateGuiBool);
	    bool getActivateGuiBool() const;
	    
	    //RGB
	    void setRedMinInt(int redMinInt);
	    int getRedMinInt() const;
	    void setGreenMinInt(int greenMinInt);
	    int getGreenMinInt() const;
	    void setBlueMinInt(int blueMinInt);
	    int getBlueMinInt() const;
        void setRedMaxInt(int redMaxInt);
        int getRedMaxInt() const;
        void setGreenMaxInt(int greenMaxInt);
        int getGreenMaxInt() const;
        void setBlueMaxInt(int blueMaxInt);
        int getBlueMaxInt() const;
        
        //HSV
        void setHMinInt(int hMinInt);
        int getHMinInt() const;
        void setSMinInt(int sMinInt);
        int getSMinInt() const;
        void setVMinInt(int vMinInt);
        int getVMinInt() const;
        void setHMaxInt(int hMaxInt);
        int getHMaxInt() const;
        void setSMaxInt(int sMaxInt);
        int getSMaxInt() const;
        void setVMaxInt(int vMaxInt);
        int getVMaxInt() const;
        
	    Publisher* getPublisher() const;
	    ~ColorDetection();

};

#endif /* COLOR_DETECTION_H */
