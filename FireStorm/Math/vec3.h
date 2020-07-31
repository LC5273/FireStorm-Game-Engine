#pragma once

#include <iostream>

class vec3
{
protected:
	float vec[3];
public:
	vec3();
	vec3(float, float, float);
	vec3(const vec3&);
	vec3& operator=(const vec3&);
	vec3 operator+(const vec3&);
	vec3& operator+=(const vec3&);
	vec3 operator-(const vec3&);
	vec3& operator-=(const vec3&);

	void setElement(int, float);
	float getElement(int) const;

	friend std::istream& operator>>(std::istream& i, vec3& v) {
		for (int k = 0; k < 3; k++)
			i >> v.vec[k];

		return i;
	}
	friend std::ostream& operator<<(std::ostream& o, const vec3& v) {
		for (int k = 0; k < 3; k++)
			o << v.vec[k] << ' ';

		return o;
	}
};

