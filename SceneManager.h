#pragma once
#include "Scene_Base.h"
#include "Scene_Title.h"
#include "Scene_Game.h"

/// <summary>
/// シーンを管理するクラス
/// </summary>
class SceneManager {
private:
	/// <summary>
	/// メンバ変数
	/// </summary>

	std::vector<Scene_Base*> sceneArr_;

	SceneNo currentScene_;
public:
	/// <summary>
	/// メンバ関数
	/// </summary>

	// コンストラクタ
	SceneManager() {

		// 各シーンのインスタンスの作成
		sceneArr_.push_back(new Scene_Title());
		sceneArr_.push_back(new Scene_Game());

		currentScene_ = TITLE;
		sceneArr_[currentScene_]->Init();
	};

	// デストラクタ
	~SceneManager() {

		for (Scene_Base* scene : sceneArr_) {

			// 各シーンの開放
			delete scene;
		}
	}

	void Run(char* keys, char* preKeys);
};