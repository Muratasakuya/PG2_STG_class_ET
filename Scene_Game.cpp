#include "Scene_Game.h"

/// <summary>
/// 初期化
/// </summary>
void Scene_Game::Init() {

	game_->Init();
}

/// <summary>
/// 更新処理
/// </summary>
void Scene_Game::Update(char* keys, char* preKeys) {

	game_->Update(keys);

	// スペースキーかコントローラーのXボタンでシーンを切り替える
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

		sceneNo_ = TITLE;
	}
}

/// <summary>
/// 描画処理
/// </summary>
void Scene_Game::Draw() {

	game_->Draw();

	/*====================================================
		デバッグ表示										*/
#ifdef _DEBUG

	Novice::ScreenPrintf(24, 24, "scene:game");

#endif
	/*==================================================*/
}