#include "mat2.h"

mat2::mat2() {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			this->mat[i][j] = 0;
}
mat2::mat2(const mat2& m) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			this->mat[i][j] = m.mat[i][j];
}
mat2& mat2::operator=(const mat2& m) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			this->mat[i][j] = m.mat[i][j];

	return *this;
}
mat2 mat2::operator+(const mat2& m) {
	mat2 M;
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			M.mat[i][j] = this->mat[i][j] + m.mat[i][j];

	return M;
}
mat2& mat2::operator+=(const mat2& m) {
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			this->mat[i][j] += m.mat[i][j];

	return *this;
}
mat2 mat2::operator-(const mat2& m) {
	mat2 M;
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			M.mat[i][j] = this->mat[i][j] - m.mat[i][j];

	return M;
}
mat2& mat2::operator-=(const mat2& m) {
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			this->mat[i][j] -= m.mat[i][j];

	return *this;
}

mat2 mat2::operator*(const mat2& m) {
	int i, j, k;
	float c[2][2] = { 0 };
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			for (k = 0; k < 2; k++)
				c[i][j] += (this->mat[j][k] * m.mat[k][j]);

	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			this->mat[i][j] = c[i][j];

	return *this;
}