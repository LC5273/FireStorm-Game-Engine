#pragma once

#include <iostream>

class vec2
{
public:
	float x;
	float y;
public:
	vec2();
	vec2(float, float);
	vec2(const vec2&);
	vec2& operator=(const vec2&);
	vec2 operator+(const vec2&);
	vec2& operator+=(const vec2&);
	vec2 operator-(const vec2&);
	vec2& operator-=(const vec2&);

	friend std::istream& operator>>(std::istream& i, vec2& v) {
		i >> v.x;
		i >> v.y;

		return i;
	}
	friend std::ostream& operator<<(std::ostream& o, const vec2& v) {
		o << v.x << ' ' << v.y;

		return o;
	}
};

