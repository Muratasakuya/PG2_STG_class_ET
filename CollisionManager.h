#pragma once
#include "Collider.h"
#include <memory>
#include <list>

/// <summary>
/// 当たり判定を管理するクラス
/// </summary>
class CollisionManager final {
private:
	// メンバ変数

	std::list<std::unique_ptr<Collider>> colliders_;

	CollisionManager() {}
	~CollisionManager() {}
	static CollisionManager* instance;

	bool CircleCheckCollsion(Collider* a, Collider* b)const;
public:
	// メンバ関数

	// コピーコンストラクタ無効化
	CollisionManager(const CollisionManager& obj) = delete;
	// 代入演算子無効化
	CollisionManager& operator=(const CollisionManager& obj) = delete;

	void AddCollider(std::unique_ptr<Collider> collider);
	void Update();

	// シングルトンの取得
	static CollisionManager* GetInstance();
};