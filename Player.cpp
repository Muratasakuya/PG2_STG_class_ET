#include "Player.h"

/// <summary>
/// コンストラクタ
/// </summary>
Player::Player() {

	for (int i = 0; i < BULLET_NUM; i++) {

		// インスタンスの作成
		bullet_[i] = new Bullet();
	}

	objType_ = ObjType::PLAYER;

	Init();
}

/// <summary>
/// 初期化
/// </summary>
void Player::Init() {

	pos_ = { 180.0f,360.0f };

	velocity_ = { 5.0f,5.0f };

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
	color_.green = 255;
	color_.blue = 255;
	color_.alpha = 255;

	channel_ =
		GetColor(color_.red, color_.green, color_.blue, color_.alpha);

	gh_ = Novice::LoadTexture("./images/white1x1.png");

	isAlive_ = true;

	/*================================
		弾の初期化 */

	for (int i = 0; i < BULLET_NUM; i++) {

		coolTime_ = 0.0f;

		// falseで初期化
		isShot_[i] = false;

		bullet_[i]->Init();
	}
}

/// <summary>
/// 動き
/// </summary>
void Player::Move(char* keys) {

	if (keys[DIK_D]) {

		pos_.x += velocity_.x;
	} else if (keys[DIK_A]) {

		pos_.x -= velocity_.x;
	}
	if (keys[DIK_S]) {

		pos_.y += velocity_.y;
	} else if (keys[DIK_W]) {

		pos_.y -= velocity_.y;
	}
}

/// <summary>
/// 更新処理
/// </summary>
void Player::Update(char* keys) {

	Move(keys);

	for (int i = 0; i < BULLET_NUM; i++) {
		// エンターキー長押しで連射
		if (!isShot_[i] && coolTime_ == 0) {
			if (keys[DIK_RETURN]) {

				bullet_[i]->SetIsAlive_(true);
				// プレイヤーの座標に弾の座標を設定
				bullet_[i]->SetPos(pos_);
				// クールタイムを元に戻す
				coolTime_ = 6.0f;
				isShot_[i] = true;

				break;
			}
		}
	}

	for (int i = 0; i < BULLET_NUM; i++) {
		// 撃たれているとき
		if (isShot_[i]) {

			// 弾が右に飛ぶ
			bullet_[i]->Update();
		}

		// 指定の座標に弾が行くと
		if (bullet_[i]->GetPos().x >= 1280.0f + bullet_[i]->GetSize().x) {

			// 次撃つまで止まる
			isShot_[i] = false;
		}
	}

	// クールタイムを-1し続ける
	if (coolTime_ > 0) {

		coolTime_--;
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
void Player::Draw() {

	if (isAlive_) {

		/*================================
				弾の描画 */
		for (int i = 0; i < BULLET_NUM; i++) {

			bullet_[i]->Draw();
		}

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