#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <Windows.h>
#include <MMSystem.h>
#include <thread>
#include "Color.h"
#include "Sound.h"


using namespace cv;
using namespace std;

//names that will appear at the top of each window
const string Yellow = "Thresholded ImageYellow";
const string Green = "Thresholded ImageGreen";
const string Blue = "Thresholded ImageBlue";
const string Red = "Thresholded ImageRed";
const string Camera = "Original";



void removeAndFill (Mat &thresh) {
		//remove small objects from the foreground
		erode(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//fill small holes in the foreground
		dilate(thresh,thresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
}

int main()
{

	cout << "W�hle ein Sound-Thema an!" << endl;
	cout << "Tiere = 1, Gitarre = 2, Gitarre2 = 3, R\201lpser = 4, Hupe = 5, Funny = 6" << endl;
	string input = "";
	int number = 0;

	do {
		cout << "bitte gib nur eine Zahl und keinen Name an!" << endl;
		getline(cin, input);
		stringstream myStream(input);
		myStream >> number;
	} while ((number < 1) || (number > 6));
	int tone = -1;


	VideoCapture cap(0); //capture the video from web cam

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}


	int x = 0;

	

	while (true)
	{cout << "es gehts weiter while" << endl;
		Mat imgOriginal, imgHSV;
		Mat thresholdR, thresholdB, thresholdG, thresholdY;
		Mat HSV;
		bool bSuccess = cap.read(imgOriginal); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		

		//**** Color Detection ***//

		//naming the colors
		Color red("red"), blue("blue"), green("green"), yellow("yellow");

		//Convert the captured frame from BGR to HSV
		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);
		
		//Red Color
		inRange(imgHSV, red.getHSVmin(), red.getHSVmax(), thresholdR);
		removeAndFill(thresholdR);

		//Blue Color
		inRange(imgHSV, blue.getHSVmin(), blue.getHSVmax(), thresholdB);
		removeAndFill(thresholdB);

		//Green Color
		inRange(imgHSV, green.getHSVmin(), green.getHSVmax(), thresholdG);
		removeAndFill(thresholdG);
		
		//Yellow Color
		inRange(imgHSV, yellow.getHSVmin(), yellow.getHSVmax(), thresholdY);
		removeAndFill(thresholdY);

	
		//*** Giving each Color tones ***//

		//Tones for Red
		Moments oMoments = moments(thresholdR);
		double dArea = oMoments.m00;

		// if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
		if (dArea > 1000000)
		{
			number = 0;
			thread t1(Sound, number, tone);
			t1.join();
		}

		//Tones for Blue
		Moments oMomentsB = moments(thresholdB);
		double dAreaB = oMomentsB.m00;

		// if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
		if (dAreaB > 1000000)
		{
			tone= 1;
			thread t2(Sound);
			t2.join();
		}

		//Tones for Green
		Moments oMomentsG = moments(thresholdG);
		double dAreaG = oMomentsG.m00;

		// if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
		if (dAreaG > 1000000)
		{
			tone = 2;
			thread t3(Sound, number, tone);
			t3.join();
		}

		//Tones for Yellow
		Moments oMomentsY = moments(thresholdY);
		double dAreaY = oMomentsY.m00;

		// if the area <= 1000000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
		if (dAreaY > 1000000)
		{
			tone = 3;
			thread t4(Sound, number, tone);
			t4.join();
		}




		//imshow(Yellow, tresholdY); //show the thresholded image
		//imshow(Green, thresholdG); //show the thresholded image
		//imshow(Blue, thresholdB); //show the thresholded image
		//imshow(Red, thresholdR); //show the thresholded image
		imshow(Camera, imgOriginal); //show the original image


		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}


	}


	return 0;

}