#pragma once

enum class EventType {
	keyPressed, keyReleased,
	MouseClickPressed, MouseClickReleased
};
enum EventCategory {
	EventCategoryInput    = 1,
	EventCategoryKeyboard = 2,
	EventCategoryMouse    = 3
};

class Event
{
public:
	Event();

};

