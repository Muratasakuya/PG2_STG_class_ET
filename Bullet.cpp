#include "Bullet.h"

/// <summary>
/// コンストラクタ
/// </summary>
Bullet::Bullet() {

	objType_ = ObjType::ENEMY;

	Init();
}

/// <summary>
/// 初期化
/// </summary>
void Bullet::Init() {

	pos_ = { -100.0f ,0.0f };

	velocity_ = { 12.0f,12.0f };

	size_ = { 8.0f,8.0f };
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

	color_.red = 0;
	color_.green = 0;
	color_.blue = 0;
	color_.alpha = 255;

	channel_ =
		GetColor(color_.red, color_.green, color_.blue, color_.alpha);

	gh_ = Novice::LoadTexture("./images/white1x1.png");

	objType_ = ObjType::ENEMY;
}

/// <summary>
/// 動き
/// </summary>
void Bullet::Move() {

	// 右方向に進む
	pos_.x += velocity_.x;
}

/// <summary>
/// 更新処理
/// </summary>
void Bullet::Update() {

	Move();

	worldMatrix_ =
		MakeAffineMatrix(scale_, theta_, pos_);

	for (int i = 0; i < VERTEX_NUM; i++) {

		worldVertex_[i] = Transform(vertex_[i], worldMatrix_);
	}
}

/// <summary>
/// 描画処理
/// </summary>
void Bullet::Draw() {

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