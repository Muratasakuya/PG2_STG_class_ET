#include "CollisionManager.h"

CollisionManager* CollisionManager::instance = nullptr;

CollisionManager* CollisionManager::GetInstance() {
	if (!instance) {
		instance = new CollisionManager();
	}
	return instance;
}

// 円の当たり判定
bool CollisionManager::CircleCheckCollsion(Collider* a, Collider* b) const {

	Vec2 d;
	float distance;

	d = a->GetPos() - b->GetPos();
	distance = sqrtf(d.x * d.x + d.y * d.y);

	if (distance < a->GetRadius() + b->GetRadius()) {

		return true;
	}

	return false;
}

void CollisionManager::AddCollider(std::unique_ptr<Collider> collider) {

	colliders_.push_back(std::move(collider));
}

void CollisionManager::Update() {

	// リストを一周して当たり判定をチェック
	for (auto itA = colliders_.begin(); itA != colliders_.end(); itA++) {
		Collider* a = itA->get();

		// 同じリスト内の次の要素から終端まで繰り返し
		for (auto itB = std::next(itA); itB != colliders_.end(); itB++) {
			Collider* b = itB->get();

			// aがPlayerで、bがPlayerのBulletの場合は当たり判定をスキップ
			if ((a->GetObjType() == ObjType::PLAYER && b->GetObjType() == ObjType::PLAERBULLET) ||
				(a->GetObjType() == ObjType::PLAERBULLET && b->GetObjType() == ObjType::PLAYER)) {

				continue;
			}

			// aとbが衝突したら
			if (CircleCheckCollsion(a, b)) {

				// 死ぬ、消える
				a->SetIsAlive_(false);
				b->SetIsAlive_(false);
			}
		}
	}
}