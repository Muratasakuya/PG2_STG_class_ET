#pragma once
#include <Novice.h>
#include "Vec2.h"
#include "Matrix3x3.h"
#include "Vertex.h"
#include "Color.h"
#include "Collider.h"

const int ENEMY_NUM = 3;

/// <summary>
/// 敵クラス
/// </summary>
class Enemy :
	public Collider {
private:
	// メンバ変数

	void Move();
public:
	// メンバ関数

	// コンストラクタ
	Enemy(Vec2 initPos);

	// デストラクタ
	~Enemy() {}

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
	bool GetIsAlive()override { return isAlive_; }

	// オブジェクトタイプの取得
	ObjType GetObjType()const override { return ObjType::ENEMY; };
};