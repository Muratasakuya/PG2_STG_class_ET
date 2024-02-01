#pragma once

/// <summary>
/// 色クラス
/// </summary>
struct Color {

	int red;
	int green;
	int blue;
	int alpha;
};

// 色の値を取得する関数
unsigned int GetColor(int red, int green, int blue, int alpha);