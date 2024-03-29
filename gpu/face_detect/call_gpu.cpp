#include "com_smc_vidproc_call_gpu.h"

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/gpu/gpu.hpp>
#include <vector>
 
using namespace std;
using namespace cv;
using namespace cv::gpu;

JNIEXPORT jint JNICALL Java_com_smc_vidproc_call_1gpu_detect
  (JNIEnv *env, jclass, jstring video_in, jstring video_out)
{
   double t = (double)getTickCount();
   const char* in;
   const char* out;
   in = env->GetStringUTFChars(video_in, 0);  
   out = env->GetStringUTFChars(video_out, 0);  
   if(in == NULL || out == NULL) {  
       std::cout << "fail to pass parameters!" << endl;
       return 0; /* OutOfMemoryError already thrown */  
   }  
   std::cout << "video_in:" << in << "video_out:" << out <<std::endl;  
   string cascadeName = "/home/ideal/hadoop-1.2.1/classifier/haarcascade_frontalface_alt.xml";
 
   VideoCapture capture(in);
   
   if(!capture.isOpened()) {
	cout << "can not open video" << endl;
	return 0;
   }
 
double fps = capture.get(CV_CAP_PROP_FPS); //get the width of frames of the video
 double dWidth = capture.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double dHeight = capture.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

   cout << "Frame Size = " << dWidth << "x" << dHeight << endl;
   cout << "FPS = " << fps<< endl;

   Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

 VideoWriter v_o (out, CV_FOURCC('D','I','V','X'), fps, frameSize, true); //initialize the VideoWriter objec
   env->ReleaseStringUTFChars(video_in, in);
   env->ReleaseStringUTFChars(video_out, out);

   CascadeClassifier_GPU cascade_gpu; 
   int gpuCnt = getCudaEnabledDeviceCount();   // gpuCnt >0 if CUDA device detected
   if(gpuCnt==0) {
	cout << "can not gpu" << endl;
	return 0;
   }
   if(!cascade_gpu.load(cascadeName)) {
     return 0;
   }
 
   Mat frame;
 
   capture >> frame;
   while(frame.data)
   {
 
      GpuMat faces;
      Mat frame_gray;
      cvtColor(frame, frame_gray, CV_BGR2GRAY);
      GpuMat gray_gpu(frame_gray);
      equalizeHist(frame_gray,frame_gray);
 
      int detect_num = cascade_gpu.detectMultiScale(
      gray_gpu, faces,
          1.2, 4, Size(20, 20) );
      Mat obj_host;
      faces.colRange(0, detect_num).download(obj_host);
 
      Rect* cfaces = obj_host.ptr<Rect>();
 
      for(int i=0;i<detect_num;++i)
      {
         Point pt1 = cfaces[i].tl();
         Size sz = cfaces[i].size();
         Point pt2(pt1.x+sz.width, pt1.y+sz.height);
         rectangle(frame, pt1, pt2, Scalar(255));
      }
//      imshow("faces", frame);
  //    if(waitKey(2)==27) break;
      v_o.write(frame);
      capture >> frame;
   }
   
   capture.release();
   v_o.release(); 
   cascade_gpu.release();
   t=((double)getTickCount()-t)/getTickFrequency();
   cout << "processing time: " << t << endl;
   return 1;
}
