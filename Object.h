#pragma once
#include <Novice.h>
#include "Vec2.h"
#include "Matrix3x3.h"
#include "Vertex.h"
#include "Color.h"

/// <summary>
/// オブジェクトの基底クラス
/// </summary>
class Object {
protected:
	// メンバ変数

	// 変換する行列
	Matrix3x3 worldMatrix_{};

	// 中心座標
	Vec2 pos_{};
	Vec2 initPos_{};

	// 速度 加速度
	Vec2 velocity_{};
	Vec2 acceleration_{};

	// 各頂点
	Vec2 vertex_[4]{};

	// 各頂点の値と行列を変換した各頂点
	Vec2 worldVertex_[4]{};

	// 大きさ
	Vec2 size_{};
	Vec2 imageSize_{};

	// 拡縮倍率
	Vec2 scale_{};

	// 回転角
	float theta_{};

	// 色の各値
	Color color_{};

	// RGB 色
	unsigned int channel_{};

	// gh
	int gh_{};

public:
	// メンバ関数

	// 仮想デストラクタ
	virtual ~Object() {}

	virtual void Init() = 0;
	virtual void Draw() = 0;

	/// <summary>
	/// ゲッター セッター
	/// </summary>
	/// <returns></returns>

	// 座標の取得
	Vec2 GetPos() { return pos_; };
	void SetPos(Vec2 pos) { pos_ = pos; }

	// サイズの取得
	Vec2 GetSize() { return size_; }
};