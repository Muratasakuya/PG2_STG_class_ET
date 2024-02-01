#pragma once
#include "Scene_Base.h"
#include "Game.h"

/// <summary>
/// ゲームシーンのクラス
/// </summary>
class Scene_Game :
	// シーンの基底クラスを継承
	public Scene_Base {
private:
	/// <summary>
	/// このクラスのメンバ変数
	/// </summary>

	Game* game_;
public:
	/// <summary>
	/// メンバ関数
	/// </summary>

	// コンストラクタ
	Scene_Game() {
	
		// インスタンスの作成
		game_ = new Game();
	}

	// デストラクタ
	~Scene_Game() {
	
		// 開放
		delete game_;
	}

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;
};