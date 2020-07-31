#include "vec2.h"

vec2::vec2() {
	x = y = 0;
}
vec2::vec2(float _x, float _y):x(_x),y(_y) {}
vec2::vec2(const vec2& v) {
	x = v.x;
	y = v.y;
}
vec2& vec2::operator=(const vec2& v) {
	x = v.x;
	y = v.y;

	return *this;
}
vec2 vec2::operator+(const vec2& v) {
	vec2 V;
	V.x = this->x + v.x;
	V.y = this->y + v.y;

	return V;
}
vec2& vec2::operator+=(const vec2& v) {
	this->x += v.x;
	this->y += v.y;

	return *this;
}
vec2 vec2::operator-(const vec2& v) {
	vec2 V;
	V.x = this->x - v.x;
	V.y = this->y - v.y;

	return V;
}
vec2& vec2::operator-=(const vec2& v) {
	this->x -= v.x;
	this->y -= v.y;

	return *this;
}