#ifndef PLUS_H_INCLUDED
#define PLUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cv;
using namespace cv::cuda;



void URUgly(Mat f, Ptr<cuda::CascadeClassifier> d, string nom);		//censors your face, f is the current frame, d is the face detector




#endif