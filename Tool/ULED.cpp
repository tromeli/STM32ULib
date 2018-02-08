/*
 * ULED.cpp
 *
 *  Created on: 2018年2月8日
 *      Author: Romeli
 */

#include <Tool/ULED.h>

ULED::ULED() {
	// TODO Auto-generated constructor stub

}


ULED::~ULED() {

}

void ULED::Init(Color color) {
	GPIOInit();
	Turn(color);
}

void ULED::Turn(Color color) {
	switch (color) {
	case Color_None:
		SetRedPin(true);
		SetGreenPin(true);
		SetBluePin(true);
		break;
	case Color_Red:
		SetRedPin(false);
		SetGreenPin(true);
		SetBluePin(true);
		break;
	case Color_Green:
		SetRedPin(true);
		SetGreenPin(false);
		SetBluePin(true);
		break;
	case Color_Blue:
		SetRedPin(true);
		SetGreenPin(true);
		SetBluePin(false);
		break;
	case Color_Yellow:
		SetRedPin(false);
		SetGreenPin(false);
		SetBluePin(true);
		break;
	case Color_Cyan:
		SetRedPin(true);
		SetGreenPin(false);
		SetBluePin(false);
		break;
	case Color_Purple:
		SetRedPin(false);
		SetGreenPin(true);
		SetBluePin(false);
		break;
	case Color_White:
		SetRedPin(false);
		SetGreenPin(false);
		SetBluePin(false);
		break;
	default:
		break;
	}
}
