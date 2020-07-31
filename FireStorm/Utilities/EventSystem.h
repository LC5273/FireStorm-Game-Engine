#pragma once

#include "Event.h"

class EventSystem
{
public:
	static EventSystem& getInstance() {
		static EventSystem instance;
		return instance;
	}
private:
	EventSystem() {}
public:
	EventSystem(const EventSystem&)           = delete;
	EventSystem operator=(const EventSystem&) = delete;
};

