/*
 * ULimit.cpp
 *
 *  Created on: 2018年1月29日
 *      Author: Romeli
 */

#include <Tool/ULimit.h>
#include <Tool/UTick.h>

ULimit::ULimit(BitAction bitAction) {
	_BitAction = bitAction;
}

ULimit::~ULimit() {
}

/*
 * author Romeli
 * explain 刷新数据(子类需实现)
 * return void
 */
void ULimit::RefreshData() {
}

/*
 * author Romeli
 * explain
 * param sensorNo 传感器号(0-255)
 * param reFresh 是否先刷新
 * return bool 触发与否
 */
bool ULimit::Check(uint8_t sensorNo, bool reFresh) {
	if (reFresh) {
		RefreshData();
	}
	return Data.at(sensorNo);
}

/*
 * author Romeli
 * explain 等待信号被触发
 * param sensorNo 传感器号(0-255)
 * param timeOut 超时时间，单位ms(0=无超时)
 * return bool false=超时
 */
bool ULimit::WaittingFor(uint8_t sensorNo, uint64_t timeOut = 0) {
	uint64_t last = UTick::Millis();
	while (!Data.at(sensorNo)) {
		if ((timeOut != 0) && (UTick::Millis() - last >= timeOut)) {
			return false;
		}
	}
	return true;
}

/*
 * author Romeli
 * explain 等待信号消失
 * param sensorNo 传感器号(0-255)
 * param timeOut 超时时间，单位ms(0=无超时)
 * return bool false=超时
 */
bool ULimit::WaittingWhile(uint8_t sensorNo, uint64_t timeOut = 0) {
	uint64_t last = UTick::Millis();
	while (!Data.at(sensorNo)) {
		if ((timeOut != 0) && (UTick::Millis() - last >= timeOut)) {
			return false;
		}
	}
	return true;
}

/*
 * author Romeli
 * explain 设置触发的电平
 * param bitAction 触发电平
 * return void
 */
void ULimit::SetActive(BitAction bitAction) {
	_BitAction = bitAction;
}
