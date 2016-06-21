#include "../include/target_aquisition/Snapshot.h"

const int NUMBER_OF_IMGS = 20;

Snapshot::Snapshot()
{
    counter = 0;
    face_cascade.load("/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml");
    eyes_cascade.load("/usr/share/opencv/haarcascades/haarcascade_eye_tree_eyeglasses.xml");
    pub = new Publisher();
}


void Snapshot::callback(const sensor_msgs::ImageConstPtr& msg)
{
    cv_bridge::CvImagePtr cv_ptr;
    cv::Mat cvImage;

    try
    {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch(cv_bridge::Exception& e)
    {
	    ROS_ERROR("cv_bridge exception: %s", e.what() );
    }

    cvImage = cv_ptr->image;
    detectAndDisplay(cvImage);

    pub->publish(cv_ptr->toImageMsg() );
}


void Snapshot::detectAndDisplay(Mat frame)
{
    std::vector<Rect> faces;
    Mat frame_gray;

    cvtColor( frame, frame_gray, CV_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(120, 120) );

    for(size_t i = 0; i < faces.size(); i++)
    {
        Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);

        // Draw circle around the user's head
        ellipse(frame, center, Size( faces[i].width*0.6, faces[i].height*0.7), 0, 0, 360, Scalar(0, 200, 0), 4, 8, 0);
        
        // Frame the person's head
        rectangle(frame, Point(center.x - faces[i].width*0.6, center.y - faces[i].height*0.7), Point(center.x + faces[i].width*0.6, center.y + faces[i].height*0.7), Scalar(0, 200, 0), 4, 8, 0);
        

        Mat faceROI = frame_gray(faces[i]);
        std::vector<Rect> eyes;

        //-- In each face, detect eyes
        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );

        for( size_t j = 0; j < eyes.size(); j++ )
        {
            Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( frame, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
        }
        
        
        
        // Save to file
        // discard first image--it may be corrupted.
        if(counter > 0 && counter < 2)
        {
            stringstream ss;
            ss << counter++;
            string buffer = ss.str();
            
            /*cout << "image width, height: " << faces[i].width << ", " << faces[i].height << endl;
            cout << "x, y, width, height: " << (center.x - faces[i].width*0.6) 
                 << ", " << (center.y - faces[i].height*0.7)
                 << ", " << (center.x + faces[i].width*2.6)
                 << ", " << (center.y + faces[i].height*2.7) << "\n\n";*/

            Rect rect(center.x - faces[i].width*0.6,
                      center.y - faces[i].height*0.7,
                      faces[i].width*1.2,
                      faces[i].height/0.7);

            if(rect.x > 0 && rect.y > 0 &&rect.width > 5 && rect.height > 5)
            {
                Mat croppedImg = frame(rect);
                cout << "saving mugshot to file..." << endl;
                imwrite("src/usar_teleop/target_acquisition/james_raw/" + buffer + ".jpg", croppedImg);
            }
        }
        else
        {
            if(counter < 100)
                counter++;
        }
        
    }
    
   
    // Show what you got
    imshow("Result", frame);
    waitKey(3);
}


Publisher* Snapshot::getPublisher()
{
    return pub;
}
     
   
Snapshot::~Snapshot()
{
    ;
}
