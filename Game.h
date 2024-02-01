#pragma once
#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"

/// <summary>
/// ゲーム画面クラス
/// </summary>
class Game{
private:
	// メンバ変数

	Player* player_;
	Enemy* enemy_[ENEMY_NUM];

public:
	// メンバ関数

	// コンストラクタ
	Game();

	// デストラクタ
	~Game() {
	
		// 開放
		delete player_;

		for (int i = 0; i < ENEMY_NUM; i++) {

			delete enemy_[i];
		}
	};

	void Init();
	void Update(char* keys);
	void Draw();

	// プレイヤーの弾の取得
	Bullet* GetPlayerBullet(int index) const {
		if (player_) {
			return player_->GetBullet(index);
		} else {
			return nullptr;
		}
	}
};