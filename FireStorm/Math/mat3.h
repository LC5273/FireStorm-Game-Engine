#pragma once

#include <iostream>

class mat3
{
protected:
	float mat[3][3];
public:
	mat3();
	mat3(const mat3&);
	mat3& operator=(const mat3&);
	mat3 operator+(const mat3&);
	mat3& operator+=(const mat3&);
	mat3 operator-(const mat3&);
	mat3& operator-=(const mat3&);
	mat3 operator*(const mat3&);

	friend std::istream& operator>>(std::istream& i, mat3& m) {
		int k, j;
		for (k = 0; k < 3; k++)
			for (j = 0; j < 3; j++)
				i >> m.mat[k][j];

		return i;
	}
	friend std::ostream& operator<<(std::ostream& o, const mat3& m) {
		int k, j;
		for (k = 0; k < 3; k++) {
			for (j = 0; j < 3; j++)
				o << m.mat[k][j] << ' ';
			o << '\n';
		}

		return o;
	}

};

