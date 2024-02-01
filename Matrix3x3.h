#pragma once
#include "Vec2.h"
#include <assert.h>

/// <summary>
/// 3x3行列
/// </summary>
struct Matrix3x3 final {

	float m[3][3];
};

Matrix3x3 MakeScaleMatrix(Vec2 scale);
Matrix3x3 MakeRotateMatrix(float theta);
Matrix3x3 MakeTranslateMatrix(Vec2 translate);
Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2);
Matrix3x3 MakeAffineMatrix(Vec2 scale, float theta, Vec2 pos);
Vec2 Transform(Vec2 vector, Matrix3x3 matrix);
Matrix3x3 Inverse3x3(Matrix3x3 matrix);