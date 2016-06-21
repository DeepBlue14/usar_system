#include "../include/target_aquisition/ColorDetection.h"


//Force initialization of static vars
bool ColorDetection::activateGuiBool = false;
int ColorDetection::redMinInt = 0;
int ColorDetection::greenMinInt = 0;
int ColorDetection::blueMinInt = 0;
int ColorDetection::redMaxInt = 0;
int ColorDetection::greenMaxInt = 0;
int ColorDetection::blueMaxInt = 0;
int ColorDetection::hMinInt = 0;
int ColorDetection::sMinInt = 0;
int ColorDetection::vMinInt = 0;
int ColorDetection::hMaxInt = 0;
int ColorDetection::sMaxInt = 0;
int ColorDetection::vMaxInt = 0;


ColorDetection::ColorDetection()
{
    pub = new Publisher();
}


void ColorDetection::callback(const sensor_msgs::ImageConstPtr& input)
{
    //initialize variables
    minX = 1000000;
    minY = 1000000;
    maxX = -100000;
    maxY = -100000;

    for(size_t i = 0; i < validXVec.size(); i++)
    {
        validXVec.pop_back();
        validYVec.pop_back();
    }

    //http://www.cse.sc.edu/~jokane/teaching/574/notes-images.pdf
    
    //convert to OpenCV type- - - - - - - - - - - - - - - - - -
    cv_bridge::CvImagePtr cv_ptr;
    cv::Mat cvImage;



    try
    {
        //http://docs.ros.org/indigo/api/sensor_msgs/html/image__encodings_8h_source.html
        cv_ptr = cv_bridge::toCvCopy(input/*, sensor_msgs::image_encodings::RGB16*/); // TYPE_32SC4
    }
    catch(cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what() );
    }
    
    m_image = cvImage = cv_ptr->image;
    
    //swap R <-> B //FIXME: use built-in image_encodings encoding
    int tmpColor;
    for(size_t a = 0; a < cvImage.rows; a++)
    {
        for(size_t b = 0; b < cvImage.cols; b++)
        {
            tmpColor = cvImage.at<cv::Vec3b>(a, b)[0];
            cvImage.at<cv::Vec3b>(a, b)[0] = cvImage.at<cv::Vec3b>(a, b)[2];
            cvImage.at<cv::Vec3b>(a, b)[2] = tmpColor;
        }
    }
    
    //BEGIN debgging windows
    cv::imshow("Initial RGB Image", cvImage);
    cv::waitKey(3);
    
    cv::Mat hsvImage;
    cvtColor(cvImage, hsvImage, COLOR_RGB2HSV);
    cv::imshow("Initial HSV Image", hsvImage);
    cv::waitKey(3);
    
    cv::inRange(cvImage,
                Scalar(getRedMinInt(), getGreenMinInt(), getBlueMinInt() ),
                Scalar(getRedMaxInt(), getGreenMaxInt(), getBlueMaxInt() ),
                cvImage);
    cv::imshow("Final RGB Image", cvImage);
    cv::waitKey(3);
    
    cv::inRange(hsvImage,
                Scalar(getHMinInt(), getSMinInt(), getVMinInt() ),
                Scalar(getHMaxInt(), getSMaxInt(), getVMaxInt() ),
                hsvImage);
    cv::imshow("Final HSV Image", hsvImage);
    cv::waitKey(3);
    //END debugging windows
    
    
    int thresh = 100;
    Mat canny_output;
    vector<vector<Point> > contours;
    vector<vector<Point> > shirts;
    vector<Vec4i> hierarchy;
    
    findContours(hsvImage, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
    
    //find object larger then a certain size
    for(size_t i = 0; i < contours.size(); i++)
    {
        //object is too small
        if(contours.at(i).size() < 125)
        {
            ;
            //cout << "size (s): " << contours.at(i).size() << endl;
        }
        //object is the right size to be a shirt
        else
        {
            //cout << "size (l): " << contours.at(i).size() << endl;
            shirts.push_back(contours.at(i) );
        }
    }
    
    cout << "# of \"shirts\": " << shirts.size() << endl;
    
    // Create polygonal contours, bounding boxes, and bounding circles around
    // each shirt-sized object of the specified color.
    RNG rng(12345);
    vector<vector<Point> > contours_poly( shirts.size() );
    vector<Rect> boundRect( shirts.size() );
    vector<Point2f>center( shirts.size() );
    vector<float>radius( shirts.size() );

    for(size_t i = 0; i < shirts.size(); i++ )
    {
        approxPolyDP( Mat(shirts[i]), contours_poly[i], 3, true );
        boundRect[i] = boundingRect( Mat(contours_poly[i]) );
        minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
    }


    // Draw the polygonal contours, bounding boxes, and bounding circles
    // into the image
    // Replace m_image with drawing if you want black background 
    //Mat drawing = Mat::zeros(hsvImage.size(), CV_8UC3 );
    for(size_t i = 0; i < shirts.size(); i++ )
    {
        Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        drawContours(m_image, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
        rectangle(m_image, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
        circle(m_image, center[i], (int)radius[i], color, 2, 8, 0 );
    }
    
    imshow("Drawing", m_image);
    waitKey(3);
    
    //Print the objects' centers of mass:
    for(size_t i = 0; i < shirts.size(); i++)
    {
        cout << "Center: (" << center[i].x  << ", " << center[i].y << ")" << endl;
    }
   
   //imshow("The_End", m_image);
   //waitKey(3);
   
   
    cv_ptr->image = m_image;
    pub->publish(cv_ptr->toImageMsg() );
}


void ColorDetection::findColor()
{
    ;
}


void ColorDetection::checkSize()
{
    ;
}


void ColorDetection::prettyPrint()
{
    ;
}


void ColorDetection::setActivateGuiBool(bool activateGuiBool)
{
    this->activateGuiBool = activateGuiBool;
}


bool ColorDetection::getActivateGuiBool() const
{
    return activateGuiBool;
}


// RGB
void ColorDetection::setRedMinInt(int redMinInt)
{
    this->redMinInt = redMinInt;
}


int ColorDetection::getRedMinInt() const
{
    return redMinInt;
}


void ColorDetection::setGreenMinInt(int greenMinInt)
{
    this->greenMinInt = greenMinInt;
}


int ColorDetection::getGreenMinInt() const
{
    return greenMinInt;
}


void ColorDetection::setBlueMinInt(int blueMinInt)
{
    this->blueMinInt = blueMinInt;
}


int ColorDetection::getBlueMinInt() const
{
    return blueMinInt;
}


void ColorDetection::setRedMaxInt(int redMaxInt)
{
    this->redMaxInt = redMaxInt;
}


int ColorDetection::getRedMaxInt() const
{
    return redMaxInt;
}


void ColorDetection::setGreenMaxInt(int greenMaxInt)
{
    this->greenMaxInt = greenMaxInt;
}


int ColorDetection::getGreenMaxInt() const
{
    return greenMaxInt;
}


void ColorDetection::setBlueMaxInt(int blueMaxInt)
{
    this->blueMaxInt = blueMaxInt;
}


int ColorDetection::getBlueMaxInt() const
{
    return blueMaxInt;
}


// HSV
void ColorDetection::setHMinInt(int hMinInt)
{
    this->hMinInt = hMinInt;
}


int ColorDetection::getHMinInt() const
{
    return hMinInt;
}


void ColorDetection::setSMinInt(int sMinInt)
{
    this->sMinInt = sMinInt;
}


int ColorDetection::getSMinInt() const
{
    return sMinInt;
}


void ColorDetection::setVMinInt(int vMinInt)
{
    this->vMinInt = vMinInt;
}


int ColorDetection::getVMinInt() const
{
    return vMinInt;
}


void ColorDetection::setHMaxInt(int hMaxInt)
{
    this->hMaxInt = hMaxInt;
}


int ColorDetection::getHMaxInt() const
{
    return hMaxInt;
}


void ColorDetection::setSMaxInt(int sMaxInt)
{
    this->sMaxInt = sMaxInt;
}


int ColorDetection::getSMaxInt() const
{
    return sMaxInt;
}


void ColorDetection::setVMaxInt(int vMaxInt)
{
    this->vMaxInt = vMaxInt;
}


int ColorDetection::getVMaxInt() const
{
    return vMaxInt;
}


Publisher* ColorDetection::getPublisher() const
{
    return pub;
}


ColorDetection::~ColorDetection()
{
    ;
}
