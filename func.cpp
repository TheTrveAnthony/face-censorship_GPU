#include <opencv2/opencv.hpp>
#include "functions.h"

using namespace std;






void URUgly(Mat f, Ptr<cuda::CascadeClassifier> d, string nom)		//censors your face, f is the current frame, d is the face detector
{
      GpuMat ff(f);
      vector<Rect> faces;

      // Convert frame to grayscale because
      // faceDetector requires grayscale image.
     
      GpuMat gray;
      cuda::cvtColor(ff, gray, COLOR_BGR2GRAY);
 
      // Detect faces
      GpuMat buf;                         // This Mat will be the output of the next method
      d->detectMultiScale(gray, buf); // This will fill our faces vector with rectangles that we'll use for the ROIs
      d->convert(buf, faces);
      
      // Let's create the filter     

      Mat censor = Mat::ones(60, 60, CV_32F)/3600;  //we use a simple mean filter to censor
      GpuMat censored(censor);      // there is no ones method for GpuMat          
      Ptr<cuda::Filter> Censoremall = cuda::createLinearFilter(CV_8U, CV_8U, censored);
    
      for( int i = 0; i < faces.size(); i++ )
         {           


            Censoremall->apply(ff(faces[i]), ff(faces[i]));
            

       }

      // Display results 
      imshow(nom, ff);


}