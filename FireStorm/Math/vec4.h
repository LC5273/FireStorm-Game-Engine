#pragma once

#include <iostream>

class vec4
{
protected:
	float vec[4];
public:
	vec4();
	vec4(float);
	vec4(float, float, float, float);
	vec4(const vec4&);

	vec4& operator=(const vec4&);
	vec4 operator+(const vec4&);
	vec4& operator+=(const vec4&);
	vec4 operator-(const vec4&);
	vec4& operator-=(const vec4&);

	bool operator==(const vec4&);
	bool operator!=(const vec4&);

	void setElement(int ,float);
	float getElement(int) const;

	friend std::istream& operator>>(std::istream& i, vec4& v) {
		for (int k = 0; k < 4; ++k)
			i >> v.vec[k];

		return i;
	}
	friend std::ostream& operator<<(std::ostream& o, const vec4& v) {
		for (int k = 0; k < 4; ++k)
			o << v.vec[k] << ' ';

		return o;
	}
};

