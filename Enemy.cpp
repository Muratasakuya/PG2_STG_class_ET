#include "Enemy.h"

/// <summary>
/// コンストラクタ
/// </summary>
Enemy::Enemy(Vec2 initPos) {

	initPos_ = initPos;

	objType_ = ObjType::ENEMY;

	Init();
}

/// <summary>
/// 初期化
/// </summary>
void Enemy::Init() {

	pos_ = initPos_;

	velocity_ = { 0.0f,5.0f };

	size_ = { 16.0f,16.0f };
	imageSize_ = { 16.0f,16.0f };

	radius_ = size_.x;

	scale_ = { 1.0f,1.0f };
	theta_ = 0.0f;

	vertex_[LT] = { -size_.x,size_.y };
	vertex_[RT] = { size_.x,size_.y };
	vertex_[LB] = { -size_.x,-size_.y };
	vertex_[RB] = { size_.x,-size_.y };

	worldMatrix_ =
		MakeAffineMatrix(scale_, theta_, pos_);

	for (int i = 0; i < VERTEX_NUM; i++) {

		worldVertex_[i] = Transform(vertex_[i], worldMatrix_);
	}

	color_.red = 255;
	color_.green = 0;
	color_.blue = 0;
	color_.alpha = 255;

	channel_ =
		GetColor(color_.red, color_.green, color_.blue, color_.alpha);

	gh_ = Novice::LoadTexture("./images/white1x1.png");

	isAlive_ = true;
}

void Enemy::Move() {

	pos_ += velocity_;

	if (pos_.y >= 720.0f - size_.y || pos_.y <= 0.0f + size_.y) {

		velocity_.y *= -1.0f;
	}
}

/// <summary>
/// 更新処理
/// </summary>
void Enemy::Update() {

	if (isAlive_) {

		Move();
	}

	// 死んだら画面外に行く
	if (!isAlive_) {

		pos_.y = -100.0f;
	}

	worldMatrix_ =
		MakeAffineMatrix(scale_, theta_, pos_);

	for (int i = 0; i < VERTEX_NUM; i++) {

		worldVertex_[i] = Transform(vertex_[i], worldMatrix_);
	}
}

/// <summary>
/// 描画処理
/// </summary>
void Enemy::Draw() {

	if (isAlive_) {

		Novice::DrawQuad(
			static_cast<int>(worldVertex_[LT].x), static_cast<int>(worldVertex_[LT].y),
			static_cast<int>(worldVertex_[RT].x), static_cast<int>(worldVertex_[RT].y),
			static_cast<int>(worldVertex_[LB].x), static_cast<int>(worldVertex_[LB].y),
			static_cast<int>(worldVertex_[RB].x), static_cast<int>(worldVertex_[RB].y),
			0, 0, static_cast<int>(imageSize_.x), static_cast<int>(imageSize_.y),
			gh_, channel_
		);
	}
}