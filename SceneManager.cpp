#include "SceneManager.h"

/// <summary>
/// 各シーンの初期化 更新処理 描画処理を行う
/// </summary>
void SceneManager::Run(char* keys, char* preKeys) {

	// 現在のシーンの取得
	currentScene_ = sceneArr_[currentScene_]->GetSceneNo();

	// 各シーンの更新と描画
	switch (currentScene_) {
	case TITLE:

		sceneArr_[TITLE]->Update(keys, preKeys);
		sceneArr_[TITLE]->Draw();

		// 現在のシーン以外のシーンの初期化
		sceneArr_[GAME]->Init();
		break;
	case GAME:

		sceneArr_[GAME]->Update(keys, preKeys);
		sceneArr_[GAME]->Draw();

		// 現在のシーン以外のシーンの初期化
		sceneArr_[TITLE]->Init();
		break;
	}
}