#include "Vec2.h"

// コンストラクタ
Vec2::Vec2() : x(0.0f), y(0.0f) {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}

// デストラクタ
Vec2::~Vec2() {}

Vec2 Vec2::operator+(const Vec2& vector) const {

	return Vec2(x + vector.x, y + vector.y);
}

Vec2 Vec2::operator-(const Vec2& vector) const {

	return Vec2(x - vector.x, y - vector.y);
}

Vec2 Vec2::operator+=(const Vec2& vector){

	this->x += vector.x;
	this->y += vector.y;
	return *this;
}

Vec2 Vec2::operator-=(const Vec2& vector) {

	this->x -= vector.x;
	this->y -= vector.y;
	return *this;
}