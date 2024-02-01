#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

/// <summary>
/// 二次元ベクトルクラス
/// </summary>
class Vec2 {
public:
	// メンバ変数

	float x;
	float y;

public:
	// メンバ関数

	// コンストラクタとデストラクタ
	Vec2();
	Vec2(float x, float y);
	~Vec2();

	// 演算子のオーバーロード
	Vec2 operator+(const Vec2& vector) const;

	Vec2 operator-(const Vec2& vector) const;

	Vec2 operator+=(const Vec2& vector);

	Vec2 operator-=(const Vec2& vector);
};