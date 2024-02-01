#include "Matrix3x3.h"

// 拡縮行列を生成する関数
Matrix3x3 MakeScaleMatrix(Vec2 scale) {
	Matrix3x3 scaleMatrix;

	scaleMatrix.m[0][0] = scale.x;
	scaleMatrix.m[0][1] = 0.0f;
	scaleMatrix.m[0][2] = 0.0f;

	scaleMatrix.m[1][0] = 0.0f;
	scaleMatrix.m[1][1] = scale.y;
	scaleMatrix.m[1][2] = 0.0f;

	scaleMatrix.m[2][0] = 0.0f;
	scaleMatrix.m[2][1] = 0.0f;
	scaleMatrix.m[2][2] = 1.0f;

	return scaleMatrix;
}

// 回転行列を生成する関数
Matrix3x3 MakeRotateMatrix(float theta) {
	Matrix3x3 rotateMatrix = {
	cosf(theta),sinf(theta),0,
	-sinf(theta),cosf(theta),0,
	0,0,1
	};
	return rotateMatrix;
}

// 平行移動行列を生成する関数
Matrix3x3 MakeTranslateMatrix(Vec2 translate) {
	Matrix3x3 translateMatrix = {
	1.0f,0,0,
	0,1.0f,0,
	translate.x,translate.y,1
	};

	return translateMatrix;
}

// 3x3行列同士の掛け算を行う関数
Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2) {

	Matrix3x3 result;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			result.m[i][j] = 0.0f;
			for (int k = 0; k < 3; k++) {

				result.m[i][j] += matrix1.m[i][k] * matrix2.m[k][j];
			}
		}
	}
	return result;
}

// アフィン変換を生成する関数
Matrix3x3 MakeAffineMatrix(Vec2 scale, float theta, Vec2 pos) {
	Matrix3x3 affinMatrix;

	Matrix3x3 scaleMatrix = MakeScaleMatrix(scale);
	Matrix3x3 roatateMatrix = MakeRotateMatrix(theta);
	Matrix3x3 translateMatrix = MakeTranslateMatrix(pos);

	affinMatrix = Multiply(scaleMatrix, roatateMatrix);
	affinMatrix = Multiply(affinMatrix, translateMatrix);

	return affinMatrix;
}

// 行列を変換する関数
Vec2 Transform(Vec2 vector, Matrix3x3 matrix) {

	Vec2 result;

	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	float w = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];

	assert(w != 0.0f);	 // もしwが0だったらプログラムを停止する
	result.x /= w;
	result.y /= w;

	return result;
}

// 3x3逆行列
Matrix3x3 Inverse3x3(Matrix3x3 matrix) {

	Matrix3x3 inverse;

	float det =
		matrix.m[0][0] * (matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1]) -
		matrix.m[0][1] * (matrix.m[1][0] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][0]) +
		matrix.m[0][2] * (matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][0]);

	float invDet = 1.0f / det;

	inverse.m[0][0] = (matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1]) * invDet;
	inverse.m[0][1] = (matrix.m[0][2] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[2][2]) * invDet;
	inverse.m[0][2] = (matrix.m[0][1] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][1]) * invDet;
	inverse.m[1][0] = (matrix.m[1][2] * matrix.m[2][0] - matrix.m[1][0] * matrix.m[2][2]) * invDet;
	inverse.m[1][1] = (matrix.m[0][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][0]) * invDet;
	inverse.m[1][2] = (matrix.m[0][2] * matrix.m[1][0] - matrix.m[0][0] * matrix.m[1][2]) * invDet;
	inverse.m[2][0] = (matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][0]) * invDet;
	inverse.m[2][1] = (matrix.m[0][1] * matrix.m[2][0] - matrix.m[0][0] * matrix.m[2][1]) * invDet;
	inverse.m[2][2] = (matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0]) * invDet;

	return inverse;
}