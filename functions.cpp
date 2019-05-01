#include <opencv2/opencv.hpp>
#include "functions.h"

using namespace std;
using namespace cv;





void URUgly(Mat f, CascadeClassifier d, string nom)		//censors your face, f is the current frame, d is the face detector
{

      vector<Rect> faces;

      // Convert frame to grayscale because
      // faceDetector requires grayscale image.
     
      Mat gray;
      cvtColor(f, gray, COLOR_BGR2GRAY);
 
      // Detect faces
      
      d.detectMultiScale(gray, faces); // This will fill our faces vector with rectangles that we'll use for the ROIs

    
      for( int i = 0; i < faces.size(); i++ )
         {           

            Mat censor = Mat::ones(60, 60, CV_32F)/3600;  //we use a simple mean filter to censor
            Point anchor = Point( -1, -1 );
            Mat censored;
            filter2D(f(faces[i]), f(faces[i]), -1, censor, anchor, 0, BORDER_DEFAULT);
            

       }

      // Display results 
      imshow(nom, f);


}