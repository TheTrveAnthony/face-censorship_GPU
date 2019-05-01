
#include <opencv2/opencv.hpp>
#include "functions.h"
#include <fstream>

 
 
using namespace std;
using namespace cv;

 
 
int main(int argc,char** argv)
{


    // Load Face Detector
    CascadeClassifier faceDetector("haarcascade_frontalface_alt2.xml");

 
    // Set up webcam for video capture
    VideoCapture cam(0);

    // Setup IP cam
    string ip ;
    /*
    ifstream get_ip("ip", ios::in);  // on ouvre en lecture

         if(get_ip)  // si l'ouverture a fonctionné

        {

                getline(get_ip, ip);  
                cout << ip << endl;  
                get_ip.close();

        } */
    cout << "Please enter your cam IP" << endl << endl ;
    cin >> ip;

    VideoCapture cam_ip;
    cam_ip.open(ip);

    if(!cam.isOpened() || !cam_ip.isOpened() ){

        cout << "the cam failed to open" << endl;
        return -1;
      }

    string loc = "cam locale";
    string ipp = "cam ip";

    namedWindow(loc, CV_WINDOW_AUTOSIZE/10); 
    namedWindow(ip, CV_WINDOW_AUTOSIZE/10);
     
    // Variable to store a video frame and its grayscale 
    Mat frame;
    Mat frame_ip;
     
    // Read a frame
    for(;;)

    {
      cam >> frame ;
      cam_ip >> frame_ip;

      URUgly(frame, faceDetector, loc);
      URUgly(frame_ip, faceDetector, ipp);

      if (waitKey(2) >= 0) break;
       
    }
    return 0;
}