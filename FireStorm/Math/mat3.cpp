#include "mat3.h"

mat3::mat3() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->mat[i][j] = 0;
}
mat3::mat3(const mat3& m) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->mat[i][j] = m.mat[i][j];
}
mat3& mat3::operator=(const mat3& m) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->mat[i][j] = m.mat[i][j];

	return *this;
}
mat3 mat3::operator+(const mat3& m) {
	mat3 M;
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			M.mat[i][j] = this->mat[i][j] + m.mat[i][j];

	return M;
}
mat3& mat3::operator+=(const mat3& m) {
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			this->mat[i][j] += m.mat[i][j];

	return *this;
}
mat3 mat3::operator-(const mat3& m) {
	mat3 M;
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			M.mat[i][j] = this->mat[i][j] - m.mat[i][j];

	return M;
}
mat3& mat3::operator-=(const mat3& m) {
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			this->mat[i][j] -= m.mat[i][j];

	return *this;
}

mat3 mat3::operator*(const mat3& m) {
	int i, j, k;
	float c[3][3] = { 0 };
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				c[i][j] += (this->mat[j][k] * m.mat[k][j]);

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			this->mat[i][j] = c[i][j];

	return *this;
}