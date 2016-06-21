/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/trajectory_rgbd/PointCloudToRangeImage.h"


PointCloudToRangeImage::PointCloudToRangeImage() : RUNS_PER_COLOR(30), COLOR_COEF(8), ABSOLUTE_MIN(0.5)
{
    pub = new Publisher();

    loop = true;
    incVal = 0.05;
    currentMin = 0.50;
    currentMax = 0.55;
}


void PointCloudToRangeImage::depthColor(PointCloud<PointXYZRGB>::Ptr input, int i)
{
    for(size_t k = 1; k < RUNS_PER_COLOR; k++)
	{
	    if(loop && input->points[i].z >= currentMin && input->points[i].z < currentMax)
	    {
	        //cout << "if found" << endl;
		    input->points[i].r = (COLOR_COEF * k);
            input->points[i].g = 0;
		    input->points[i].b = 0;
	   	    loop = false;
		    break;//NOTE: need to break OUTER loop
	    }
	
	    currentMin += incVal;		
	    currentMax += incVal;
	}
}


void PointCloudToRangeImage::callback(PointCloud<PointXYZRGB>::Ptr input)
{
    pcl::RangeImage pclRi = toPclRangeImage(input);   
    


    for(size_t i = 0; i < input->points.size(); i++)
    {

        if( !(input->points[i].z > 0.0 && input->points[i].z < 20.0) )
	    {
	        loop = false; //NaN value
	        //break;
	    }
	
        if( (input->points[i].z >= 0.0 && input->points[i].z < ABSOLUTE_MIN) || input->points[i].z > 13)
	    {
	        //cout << "if found" << endl;
	        input->points[i].r = 4;
	        input->points[i].g = 0;
	        input->points[i].b = 0;
	        loop = false;
	        //break;//NOTE: need to break OUTER loop
	    }

	    /*for(size_t k = 1; k < RUNS_PER_COLOR; k++)
	    {
	        if(loop && input->points[i].z >= currentMin && input->points[i].z < currentMax)
	        {
		        //cout << "if found" << endl;
		        input->points[i].r = (COLOR_COEF * k);
		        input->points[i].g = 0;
		        input->points[i].b = 0;
	   	        loop = false;
		        break;//NOTE: need to break OUTER loop
	        }
	
	        currentMin += incVal;
	        currentMax += incVal;
	    }*/
        depthColor(input, i);

	    //red
	    for(size_t k = 1; k < RUNS_PER_COLOR; k++)
	    {
	        if(loop && input->points[i].z >= currentMin && input->points[i].z < currentMax)
	        {
	    	    input->points[i].r = 255;
	    	    input->points[i].g = (COLOR_COEF * k);
	    	    input->points[i].b = 0;
		        loop = false;
		        break;
	        }

	        currentMin += incVal;
	        currentMax += incVal;
	    }

	    //red-yellow-green
	    for(size_t k = 1; k < RUNS_PER_COLOR; k++)
	    {
	        if(loop && input->points[i].z >= currentMin && input->points[i].z < currentMax)
	        {
	    	    input->points[i].r = (255 - (COLOR_COEF * k) );
	    	    input->points[i].g = 255;
	    	    input->points[i].b = 0;
		        loop = false;
		        break;
	        }

	        currentMin += incVal;
	        currentMax += incVal;
	    }

	    //green-blue
	    for(size_t k = 1; k < RUNS_PER_COLOR; k++)
	    {
	        if(loop && input->points[i].z >= currentMin && input->points[i].z < currentMax)
	        {
	    	    input->points[i].r = 0;//(255 - (COLOR_COEF * k) );
	    	    input->points[i].g = 255;
	    	    input->points[i].b = (COLOR_COEF * k);
		        loop = false;
		        break;
	        }

	        currentMin += incVal;
	        currentMax += incVal;
	    }

	    //blue
	    for(size_t k = 1; k < RUNS_PER_COLOR; k++)
	    {
	        if(loop && input->points[i].z >= currentMin && input->points[i].z < currentMax)
	        {
	    	    input->points[i].r = 0;
	    	    input->points[i].g = (255 - (COLOR_COEF * k) );
	    	    input->points[i].b = 255;
		        loop = false;
		        break;
	        }

	        currentMin += incVal;
	        currentMax += incVal;
	    }


	    loop = true;
	    currentMin = 0.50;
	    currentMax = 0.55;
    }


    pub->publish(*input);
}


Publisher* PointCloudToRangeImage::getPublisher()
{
    return pub;
}


RangeImage PointCloudToRangeImage::toPclRangeImage(PointCloud<PointXYZRGB>::Ptr input)
{
    float angularResolution = (float) (  1.0f * (M_PI/180.0f));  //   1.0 degree in radians
    float maxAngleWidth     = (float) (360.0f * (M_PI/180.0f));  // 360.0 degree in radians
    float maxAngleHeight    = (float) (180.0f * (M_PI/180.0f));  // 180.0 degree in radians
    Eigen::Affine3f sensorPose = (Eigen::Affine3f)Eigen::Translation3f(0.0f, 0.0f, 0.0f);
    RangeImage::CoordinateFrame coordinate_frame = RangeImage::CAMERA_FRAME;
    float noiseLevel=0.00;
    float minRange = 0.0f;
    int borderSize = 1;
  
    RangeImage rangeImage;
    rangeImage.createFromPointCloud(*input, angularResolution, maxAngleWidth, maxAngleHeight,
                                  sensorPose, coordinate_frame, noiseLevel, minRange, borderSize); 

    return rangeImage;
}


PointCloudToRangeImage::~PointCloudToRangeImage()
{
    ;
}
