#include "Game.h"

/// <summary>
/// コンストラクタ
/// </summary>
Game::Game() {

	// インスタンスの作成
	player_ = new Player();

	for (int i = 0; i < ENEMY_NUM; i++) {

		enemy_[i] = new Enemy({ 800.0f + i * 100.0f,120.0f + i * 120.0f });
	}

	// ColliderをCollisionManagerに登録
	// プレイヤー
	CollisionManager::GetInstance()->AddCollider(std::unique_ptr<Collider>(player_));
	for (int i = 0; i < ENEMY_NUM; i++) {
		// 敵
		CollisionManager::GetInstance()->AddCollider(std::unique_ptr<Collider>(enemy_[i]));
	}
	for (int i = 0; i < BULLET_NUM; i++) {
		Bullet* playerBullet = GetPlayerBullet(i);
		if (playerBullet) {
			// プレイヤーの弾
			CollisionManager::GetInstance()->AddCollider(std::unique_ptr<Collider>(playerBullet));
		}
	}

	Init();
};

/// <summary>
/// 初期化
/// </summary>
void Game::Init() {

	player_->Init();

	for (int i = 0; i < ENEMY_NUM; i++) {

		enemy_[i]->Init();
	}
}

/// <summary>
/// 更新処理
/// </summary>
void Game::Update(char* keys) {

	player_->Update(keys);

	for (int i = 0; i < ENEMY_NUM; i++) {

		enemy_[i]->Update();
	}

	// CollisionManagerの更新
	CollisionManager::GetInstance()->Update();
}

/// <summary>
/// 描画処理
/// </summary>
void Game::Draw() {

	player_->Draw();

	for (int i = 0; i < ENEMY_NUM; i++) {

		enemy_[i]->Draw();
	}
}