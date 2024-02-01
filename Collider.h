#pragma once
#include "Object.h"

// 当たり判定を行うオブジェクトの種類
enum class ObjType {

	PLAYER,
	PLAERBULLET,
	ENEMY
};

/// <summary>
/// 当たり判定を行う基底クラス
/// </summary>
class Collider {
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

	// 半径
	float radius_{};

	// 生きているかどうかのフラグ
	bool isAlive_{};

	ObjType objType_{};

public:
	// メンバ関数

	// 仮想デストラクタ
	virtual ~Collider() = default;

	/// <summary>
	/// ゲッター セッター
	/// </summary>
	/// <returns></returns>

	// 座標の取得
	virtual Vec2 GetPos() = 0;

	// サイズの取得
	virtual Vec2 GetSize() = 0;
	virtual float GetRadius() = 0;

	// 生存フラグの設定
	virtual void SetIsAlive_(bool isAlive) = 0;
	virtual bool GetIsAlive() { return isAlive_; }

	// オブジェクトタイプの取得
	virtual ObjType GetObjType() const = 0;
};