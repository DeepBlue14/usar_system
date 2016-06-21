/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/trajectory_rgbd/CenterDepth.h"

CenterDepth::CenterDepth()
{
    isInRange.data = false;
    pub = new Publisher();
}


void CenterDepth::callback(PointCloud<PointXYZRGB>::Ptr input)
{
    Mat cvImage = Mat::zeros(480, 640, CV_8UC3);

    int pclCount = 0;
    float sum = 0.0;
    int inRangeCount = 0;
    float average = 0.0;
    for(size_t y = 0; y < cvImage.rows; y++)
    {
        for(size_t x = 0; x < cvImage.cols; x++)
        {
            cvImage.at<Vec3b>(Point(x, y)).val[2] = input->points[pclCount].r;
            cvImage.at<Vec3b>(Point(x, y)).val[1] = input->points[pclCount].g;
            cvImage.at<Vec3b>(Point(x, y)).val[0] = input->points[pclCount].b;
            
            if(y > 230 && y < 250 && x > 310 && x < 330)
            {
                cvImage.at<Vec3b>(Point(x, y)).val[2] = 250;
                cvImage.at<Vec3b>(Point(x, y)).val[1] = 0;
                cvImage.at<Vec3b>(Point(x, y)).val[0] = 75;
            
                if(input->points[pclCount].z > 0 && input->points[pclCount].z < 100)
                {
                    sum += input->points[pclCount].z;
                }
                inRangeCount++;
            }

            pclCount++;
        }
    }
    
    average = sum/inRangeCount;
    cout << "Average depth: " << average << endl;
    if(average > 2.0)
    {
        isInRange.data = false;
    }
    else
    {
        isInRange.data = true;
    }
    
    imshow("Image", cvImage);
    waitKey(3);
    
    pub->publish(isInRange);
}


Publisher* CenterDepth::getPublisher() const
{
    return pub;
}


char* CenterDepth::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


CenterDepth::~CenterDepth()
{
    ;
}
