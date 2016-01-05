#include "Sound.h"


Sound::Sound ()

{
	if (getNumber() == 1) {
		switch (getTone()) {
		case(0):
			PlaySound(TEXT("horse1a.wav"), NULL, SND_SYNC);
			break;
		case(1):
			PlaySound(TEXT("hen2.wav"), NULL, SND_SYNC);
			break;
		case(2):
			PlaySound(TEXT("crow1a.wav"), NULL, SND_SYNC);
			break;
		case(3):
			PlaySound(TEXT("lamb.wav"), NULL, SND_SYNC);
			break;
		default:
			break;
		}
		
		
	}else if (getNumber() == 2) {
		switch (getTone()) {
		case(0) :
			PlaySound(TEXT("g (1).wav"), NULL, SND_SYNC);
			break;
		case(1) :
			PlaySound(TEXT("g (2).wav"), NULL, SND_SYNC);
			break;
		case(2) :
			PlaySound(TEXT("g (3).wav"), NULL, SND_SYNC);
			break;
		case(3) :
			PlaySound(TEXT("g (4).wav"), NULL, SND_SYNC);
			break;
		default:
			break;
		}


	}
	else if (getNumber() == 3) {
		switch (getTone()) {
		case(0) :
			PlaySound(TEXT("gb (1).wav"), NULL, SND_SYNC);
			break;
		case(1) :
			PlaySound(TEXT("gb (2).wav"), NULL, SND_SYNC);
			break;
		case(2) :
			PlaySound(TEXT("gb (3).wav"), NULL, SND_SYNC);
			break;
		case(3) :
			PlaySound(TEXT("gb (4).wav"), NULL, SND_SYNC);
			break;
		default:
			break;
		}


	}
	else if (getNumber() == 4) {
		switch (getTone()) {
		case(0) :
			PlaySound(TEXT("r (1).wav"), NULL, SND_SYNC);
			break;
		case(1) :
			PlaySound(TEXT("r (2).wav"), NULL, SND_SYNC);
			break;
		case(2) :
			PlaySound(TEXT("r (3).wav"), NULL, SND_SYNC);
			break;
		case(3) :
			PlaySound(TEXT("r (4).wav"), NULL, SND_SYNC);
			break;
		default:
			break;
		}
	}
	else if (getNumber() == 5) {
		switch (getTone()) {
		case(0) :
			PlaySound(TEXT("h (1).wav"), NULL, SND_SYNC);
			break;
		case(1) :
			PlaySound(TEXT("h (2).wav"), NULL, SND_SYNC);
			break;
		case(2) :
			PlaySound(TEXT("h (3).wav"), NULL, SND_SYNC);
			break;
		case(3) :
			PlaySound(TEXT("h (4).wav"), NULL, SND_SYNC);
			break;
		default:
			break;
		}


	}
	else if (getNumber() == 6) {
		switch (getTone()) {
		case(0) :
			PlaySound(TEXT("ich (1).wav"), NULL, SND_SYNC);
			break;
		case(1) :
			PlaySound(TEXT("ich (2).wav"), NULL, SND_SYNC);
			break;
		case(2) :
			PlaySound(TEXT("ich (3).wav"), NULL, SND_SYNC);
			break;
		case(3) :
			PlaySound(TEXT("ich (4).wav"), NULL, SND_SYNC);
			break;
		default:
			break;
		}
	}
}


int Sound::getNumber(){
	return Sound::number;
}

int Sound::getTone(){
	return Sound::tone;
}


void Sound::setNumber(int number){
	Sound::number=number;
}

void Sound::setTone(int tone){
	Sound::tone=tone;
}
