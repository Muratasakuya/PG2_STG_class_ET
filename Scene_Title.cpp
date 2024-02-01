#include "Scene_Title.h"

/// <summary>
/// 初期化
/// </summary>
void Scene_Title::Init() {


}

/// <summary>
/// 更新処理
/// </summary>
void Scene_Title::Update(char* keys, char* preKeys) {

	// スペースキーかコントローラーのXボタンでシーンを切り替える
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

		sceneNo_ = GAME;
	}
}

/// <summary>
/// 描画処理
/// </summary>
void Scene_Title::Draw() {

	/*====================================================
		デバッグ表示										*/
#ifdef _DEBUG

	Novice::ScreenPrintf(24, 24, "scene:title");

#endif
	/*===================================================*/
}