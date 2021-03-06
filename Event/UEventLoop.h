/*
 * UEventLoop.h
 *
 *  Created on: 2018年1月24日
 *      Author: Romeli
 */

#ifndef UEVENTLOOP_H_
#define UEVENTLOOP_H_

#include <cmsis_device.h>
#include <Tool/UTick.h>
#include <Misc/UMisc.h>
#include <list>

class UEventLoop {
public:
	struct Unit_Typedef {
		Unit_Typedef(UEvent event, uint64_t interval) {
			//事件回调函数
			Event = event;
			//事件回调时间间隔
			Interval = interval;
			//事件上次回调时间
			LastCall = 0;
		}
		UEvent Event;
		uint64_t Interval;
		uint64_t LastCall;
	};

	typedef std::list<Unit_Typedef> EventList;

	virtual ~UEventLoop();

	void TryDo();
	void Insert(UEvent event, uint64_t interval, bool isMicroSecond = false);
	void Remove(UEvent event);
	void Clear();
private:
	EventList _List;
};

#endif /* UEVENTLOOP_H_ */
