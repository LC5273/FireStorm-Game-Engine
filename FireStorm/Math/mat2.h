#pragma once

#include <iostream>

class mat2
{
protected:
	float mat[2][2];
public:
	mat2();
	mat2(const mat2&);
	mat2& operator=(const mat2&);
	mat2 operator+(const mat2&);
	mat2& operator+=(const mat2&);
	mat2 operator-(const mat2&);
	mat2& operator-=(const mat2&);
	mat2 operator*(const mat2&);

	friend std::istream& operator>>(std::istream& i, mat2& m) {
		int k, j;
		for (k = 0; k < 2; k++)
			for (j = 0; j < 2; j++)
				i >> m.mat[k][j];

		return i;
	}
	friend std::ostream& operator<<(std::ostream& o, const mat2& m) {
		int k, j;
		for (k = 0; k < 2; k++) {
			for (j = 0; j < 2; j++)
				o << m.mat[k][j] << ' ';
			o << '\n';
		}

		return o;
	}

};

