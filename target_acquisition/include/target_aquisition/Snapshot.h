/*
 * File Description: This class will detect a face, and then take a series of snapshots of it.
 */
 
#ifndef SNAPSHOT_H
#define SNAPSHOT_H

#include <ros/ros.h>
#include <sensor_msgs/Image.h>

#include <opencv/cv.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>

#include <stdlib.h>
#include <stdio.h>
#include <sstream>

#include <iostream>

using namespace ros;
using namespace cv;
using namespace std;

extern const int NUMBER_OF_IMGS;

class Snapshot
{
    private:
        
        int counter;
        CascadeClassifier face_cascade;
        CascadeClassifier eyes_cascade;
        Publisher* pub;
        
    public:
        Snapshot();
        void callback(const sensor_msgs::ImageConstPtr& msg);
        void detectAndDisplay(Mat frame);
        Publisher* getPublisher();
        ~Snapshot();
};

#endif /* SNAPSHOT_H */
