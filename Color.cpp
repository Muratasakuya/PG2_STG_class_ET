#include "Color.h"

unsigned int GetColor(int red, int green, int blue, int alpha) {

	int color = 0;

	// 赤
	color |= (red & 0xFF) << 24;
	// 緑
	color |= (green & 0xFF) << 16;
	// 青
	color |= (blue & 0xFF) << 8;

	// アルファ
	color |= (alpha & 0xFF);

	return color;
}