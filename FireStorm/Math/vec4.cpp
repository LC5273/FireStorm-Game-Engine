#include "vec4.h"

vec4::vec4() {
	this->vec[0] = 0;
	this->vec[1] = 0;
	this->vec[2] = 0;
	this->vec[3] = 0;
}
vec4::vec4(float x) {
	for (int i = 0; i < 4; ++i)
		this->vec[i] = x;
}
vec4::vec4(float x, float y, float z, float w) {
	this->vec[0] = x;
	this->vec[1] = y;
	this->vec[2] = z;
	this->vec[3] = w;
}
vec4::vec4(const vec4& v) {
	for (int i = 0; i < 4; ++i)
		this->vec[i] = v.vec[i];
}


vec4& vec4::operator=(const vec4& v) {
	for (int i = 0; i < 4; ++i)
		this->vec[i] = v.vec[i];

	return *this;
}
vec4 vec4::operator+(const vec4& v) {
	vec4 V;
	for (int i = 0; i < 4; ++i)
		V.vec[i] = this->vec[i] + v.vec[i];

	return V;
}
vec4& vec4::operator+=(const vec4& v) {
	for (int i = 0; i < 4; ++i)
		this->vec[i] += v.vec[i];

	return *this;
}
vec4 vec4::operator-(const vec4& v) {
	vec4 V;
	for (int i = 0; i < 4; ++i)
		V.vec[i] = this->vec[i] - v.vec[i];

	return V;
}
vec4& vec4::operator-=(const vec4& v) {
	for (int i = 0; i < 4; ++i)
		this->vec[i] -= v.vec[i];

	return *this;
}


bool vec4::operator==(const vec4& v) {
	for(int i = 0; i < 4; ++i) 
		if (this->vec[i] != v.vec[i])
			return false;
	return true;
}
bool vec4::operator!=(const vec4& v) {
	for (int i = 0; i < 4; ++i)
		if (this->vec[i] != v.vec[i])
			return true;
	return false;

	return !(*this == v);
}


void vec4::setElement(int poz, float value) {
	this->vec[poz] = value;
}
float vec4::getElement(int poz) const {
	return this->vec[poz];
}