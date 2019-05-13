
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/core/opengl.hpp>
#include <opencv4/opencv2/cudacodec.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include "functions.h"
#include <fstream>

 
 
using namespace std;
using namespace cv;
using namespace cv::cuda;

 
 
int main(int argc,char** argv)
{


    // Load Face Detector
    Ptr<cuda::CascadeClassifier> faceDetector = cuda::CascadeClassifier::create("haarcascade_frontalface_alt2.xml");

 
    // Set up webcam for video capture
    //Ptr<cv::cudacodec::VideoReader> cam_l = cv::cudacodec::createVideoReader("eruk"); 
    VideoCapture cam_l(0);

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

    //Ptr<cv::cudacodec::VideoReader> cam_ip = cv::cudacodec::createVideoReader(ip);
    VideoCapture cam_ip;
    cam_ip.open(ip);
/*
    if(!cam_l.isOpened() || !cam_ip.isOpened() ){

        cout << "the cam failed to open" << endl;
        return -1;
      } */

    string loc = "cam locale";
    string ipp = "cam ip";

    namedWindow(loc, WINDOW_OPENGL); 
    namedWindow(ip, WINDOW_OPENGL);
    cuda::setGlDevice();
     
    // Variable to store a video frame and its grayscale 
    Mat frame;
    Mat frame_ip;
     
    // Read a frame
    for(;;)

    {
      cam_l >> frame ;
      cam_ip >> frame_ip;    // Can't use this syntax with cuda, I liked it ><

      // so instead :

      //if(!cam_l->nextFrame(frame) || !cam_ip->nextFrame(frame_ip)) break;

      URUgly(frame, faceDetector, loc);
      URUgly(frame_ip, faceDetector, ipp);

      if (waitKey(2) >= 0) break;
       
    }
    return 0;
}