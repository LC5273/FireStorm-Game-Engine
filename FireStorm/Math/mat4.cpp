#include "mat4.h"

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

inline float toRadiants(float degrees) {
	return (degrees * M_PI) / 180.0f;
}

mat4::mat4() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			this->mat[i][j] = 0;
}
mat4::mat4(const mat4& m) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			this->mat[i][j] = m.mat[i][j];
}

void mat4::elements(float e[16]) const {
	//float e[16];

	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			e[i + j * 4] = this->mat[i][j];

	//return e;
}

float* mat4::elements1() const { //implement using smartpointer - memory leak
	float* x;
	x = new float[16];

	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			x[i + j * 4] = this->mat[i][j];

	return x;
}

mat4& mat4::operator=(const mat4& m) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			this->mat[i][j] = m.mat[i][j];
	
	return *this;
}
mat4 mat4::operator+(const mat4& m) {
	mat4 M;
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			M.mat[i][j] = this->mat[i][j] + m.mat[i][j];

	return M;
}
mat4& mat4::operator+=(const mat4& m) {
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			this->mat[i][j] += m.mat[i][j];

	return *this;
}
mat4 mat4::operator-(const mat4& m) {
	mat4 M;
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			M.mat[i][j] = this->mat[i][j] - m.mat[i][j];

	return M;
}
mat4& mat4::operator-=(const mat4& m) {
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			this->mat[i][j] -= m.mat[i][j];

	return *this;
}

mat4 mat4::operator*(const mat4& m) {
	int i, j, k;
	float c[4][4] = { 0 };
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			for (k = 0; k < 4; k++)
				c[i][j] += (this->mat[j][k] * m.mat[k][j]);
	
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			this->mat[i][j] = c[i][j];
	
	return *this;
}

mat4 mat4::identity() {
	mat4 m;
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (i == j) m.mat[i][j] = 1;
			else m.mat[i][j] = 0;

	return m;
}

mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far) {
	mat4 m = identity();
	m.mat[0][0] = 2.0f / (right - left);
	m.mat[1][1] = 2.0f / (top - bottom);
	m.mat[2][2] = 2.0f / (far - near);  //-2.0f

	m.mat[0][3] = (right + left) / (right - left);
	m.mat[1][3] = (top + bottom) / (top - bottom);
	m.mat[2][3] = (far + near) / (far - near);

	return m;
}

mat4 mat4::perspective(float fov, float aspectRatio, float near, float far) {
	mat4 m = identity();
	float x = 1.0f / tan((toRadiants(0.5f * fov)));

	m.mat[0][0] = x / aspectRatio;
	m.mat[1][1] = x;
	m.mat[2][2] = (near + far) / (far - near);
	m.mat[3][3] = 0;

	m.mat[2][3] = (2.0f * near * far) / (near - far);
	m.mat[3][2] = 1.0f;

	//or mat[2][3] and mat[3][2] *= -1.0f
	//or mat[2][2] near-far

	return m;
}

mat4 mat4::translation(const vec3& t) {
	mat4 m = identity();

	m.mat[0][3] = t.getElement(0);
	m.mat[1][3] = t.getElement(1);
	m.mat[2][3] = t.getElement(2);

	return m;
}

mat4 mat4::scale(const vec3& s) {
	mat4 m = identity();

	m.mat[0][0] = s.getElement(0);
	m.mat[1][1] = s.getElement(1);
	m.mat[2][2] = s.getElement(2);

	return m;
}

mat4 mat4::rotation(float angle, const vec3& axis) {
	mat4 m = identity();

	float rad = toRadiants(angle);
	float s = sin(rad);
	float c = cos(rad);
	float oc = 1.0f - c;

	float x = axis.getElement(0);
	float y = axis.getElement(1);
	float z = axis.getElement(2);

	m.mat[0][0] = x * oc + c;
	m.mat[1][0] = x * y * oc + z * s;
	m.mat[2][0] = x * z * oc - y * s;

	m.mat[0][1] = x * y * oc - z * s;
	m.mat[1][1] = y * oc + c;
	m.mat[2][1] = y * z * oc + x * s;

	m.mat[0][2] = x * z * oc + y * s;
	m.mat[1][2] = y * z * oc - x * s;
	m.mat[2][2] = z * oc + c;

	return m;
}


void mat4::setElement(int x, int y, float z) {
	if (x >= 0 && x < 4 && y >= 0 && y < 4)
		this->mat[x][y] = z;
	else
		std::cout << "Invalid parameters";
}

float mat4::getElement(int x, int y) const {
	if(x>=0 && x<4 && y>=0 && y<4)
		return this->mat[x][y];

	return -1000.0f;
}
