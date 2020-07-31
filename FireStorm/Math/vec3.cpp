#include "vec3.h"

vec3::vec3() {}
vec3::vec3(float x, float y, float z) {
	this->vec[0] = x;
	this->vec[1] = y;
	this->vec[2] = z;
}
vec3::vec3(const vec3& v) {
	for (int i = 0; i < 3; i++)
		this->vec[i] = v.vec[i];
}
vec3& vec3::operator=(const vec3& v) {
	for (int i = 0; i < 3; i++)
		this->vec[i] = v.vec[i];

	return *this;
}
vec3 vec3::operator+(const vec3& v) {
	vec3 V;
	for (int i = 0; i < 3; i++)
		V.vec[i] = this->vec[i] + v.vec[i];

	return V;
}
vec3& vec3::operator+=(const vec3& v) {
	for (int i = 0; i < 3; i++)
		this->vec[i] += v.vec[i];

	return *this;
}
vec3 vec3::operator-(const vec3& v) {
	vec3 V;
	for (int i = 0; i < 3; i++)
		V.vec[i] = this->vec[i] - v.vec[i];

	return V;
}
vec3& vec3::operator-=(const vec3& v) {
	for (int i = 0; i < 3; i++)
		this->vec[i] -= v.vec[i];

	return *this;
}


void vec3::setElement(int poz, float value) {
	this->vec[poz] = value;
}

float vec3::getElement(int poz) const {
	return this->vec[poz];
}