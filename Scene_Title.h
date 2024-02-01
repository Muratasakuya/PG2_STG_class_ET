#pragma once
#include "Scene_Base.h"

/// <summary>
/// タイトルシーンのクラス
/// </summary>
class Scene_Title :
	// シーンの基底クラスを継承
	public Scene_Base {
private:
	/// <summary>
	/// このクラスのメンバ変数
	/// </summary>


public:
	/// <summary>
	/// メンバ関数
	/// </summary>

	// コンストラクタ
	Scene_Title() {}

	// デストラクタ
	~Scene_Title() {}

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;
};