#pragma once
#include <Novice.h>
#include "Vec2.h"
#include "Matrix3x3.h"
#include "Vertex.h"
#include "Color.h"
#include "Collider.h"
#include "Bullet.h"

const int BULLET_NUM = 5;

/// <summary>
/// プレイヤーの弾クラス
/// </summary>
class Bullet :
	public Collider {
private:
	// メンバ変数

	void Move();
public:
	// メンバ関数

	// コンストラクタ
	Bullet();

	// デストラクタ
	~Bullet() {}

	void Init();
	void Update();
	void Draw();

	/// <summary>
	/// ゲッター セッター
	/// </summary>
	/// <returns></returns>

	// 座標の取得
	Vec2 GetPos()override { return pos_; };
	void SetPos(Vec2 pos) { pos_ = pos; };

	// サイズの取得
	Vec2 GetSize()override { return size_; };
	float GetRadius()override { return radius_; };

	// 生存フラグの設定
	void SetIsAlive_(bool isAlive)override { isAlive_ = isAlive; };

	// オブジェクトタイプの取得
	ObjType GetObjType()const override { return ObjType::PLAERBULLET; };
};