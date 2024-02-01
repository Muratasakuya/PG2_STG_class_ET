#pragma once
#include <Novice.h>
#include "Vec2.h"
#include "Matrix3x3.h"
#include "Vertex.h"
#include "Color.h"
#include "Collider.h"
#include "Bullet.h"

/// <summary>
/// プレイヤークラス
/// </summary>
class Player :
	public Collider {
private:
	// メンバ変数

	Bullet* bullet_[BULLET_NUM];

	// 連射のクールタイム
	float coolTime_;

	// 弾が撃たれているか判断するフラグ
	bool isShot_[BULLET_NUM];

	void Move(char* keys);
public:
	// メンバ関数

	// コンストラクタ
	Player();

	// デストラクタ
	~Player() {
		for (int i = 0; i < BULLET_NUM; i++) {

			// 開放
			delete bullet_[i];
		}
	}

	void Init();
	void Update(char* keys);
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
	ObjType GetObjType()const override { return ObjType::PLAYER; };

	// 弾の取得
	Bullet* GetBullet(int index) const {
		if (index >= 0 && index < BULLET_NUM) {
			return bullet_[index];
		} else {
			return nullptr;
		}
	}
};