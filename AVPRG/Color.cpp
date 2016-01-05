#include "Color.h"

Color::Color(string name){
	//setType(name);
	
	if(name =="red"){
		setHSVmin(Scalar(131, 113, 40));
		setHSVmax(Scalar(190, 255, 255));
	}
	if(name =="blue"){
		setHSVmin(Scalar(87, 116, 0));
		setHSVmax(Scalar(145, 255, 255));
	}
	if(name =="green"){
		setHSVmin(Scalar(38, 88, 0));
		setHSVmax(Scalar(97, 198, 255));
	}
	if(name =="yellow"){
		setHSVmin(Scalar(0, 43, 255));
		setHSVmax(Scalar(37, 165, 255));
	}
	
}

Scalar Color::getHSVmin(){
	return Color::HSVmin;
}

Scalar Color::getHSVmax(){
	return Color::HSVmax;
}

void Color::setHSVmin(Scalar min){
	Color::HSVmin = min;
}

void Color::setHSVmax(Scalar max){
	Color::HSVmax = max;
}