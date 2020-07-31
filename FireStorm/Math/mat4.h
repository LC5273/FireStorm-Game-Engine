#pragma once

#include <iostream>
#include "vec4.h"
#include "vec3.h"

class mat4
{
protected:
	float mat[4][4];
public:
	mat4();
	mat4(const mat4&);

	void elements(float[16]) const;
	float* elements1() const;

	mat4& operator=(const mat4&);
	mat4 operator+(const mat4&);
	mat4& operator+=(const mat4&);
	mat4 operator-(const mat4&);
	mat4& operator-=(const mat4&);
	mat4 operator*(const mat4&);
	
	friend vec4 operator*(const mat4& m, const vec4& v) {
		vec4 result(0.0);
		int i, j;
		float x;
		for (i = 0; i < 4; ++i) {
			x = 0;
			for (j = 0; j < 4; ++j) {
				x += m.mat[i][j] * v.getElement(j);
				result.setElement(i, x);
			}
		}

		return result;
	}

	static mat4 identity();
	static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
	static mat4 perspective(float fov, float aspectRatio, float near, float far);

	static mat4 translation(const vec3& t);
	static mat4 rotation(float angle, const vec3& axis);
	static mat4 scale(const vec3& s);

	void setElement(int, int, float);
	float getElement(int, int) const;

	friend std::istream& operator>>(std::istream& i, mat4& m) {
		int k, j;
		for (k = 0; k < 4; k++)
			for (j = 0; j < 4; j++)
				i >> m.mat[k][j];
		
		return i;
	}
	friend std::ostream& operator<<(std::ostream& o, const mat4& m) {
		int k, j;
		for (k = 0; k < 4; k++) {
			for (j = 0; j < 4; j++)
				o << m.mat[k][j] << ' ';
			o << '\n';
		}
		
		return o;
	}
	
};

