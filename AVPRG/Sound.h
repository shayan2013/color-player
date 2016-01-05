#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <Windows.h>
#include <MMSystem.h>
#include <thread>

using namespace cv;
using namespace std;

class Sound
{
public:
	Sound();
		
	int getNumber();
	int getTone();
	
	void setNumber(int number);
	void setTone(int tone);
	
private:
	int number;
	int tone;

};