#pragma once
#include <vector>
#include <Novice.h>

// シーンの数
const int SCENE_NUM = 2;

// シーンの種類
enum SceneNo {

	TITLE,
	GAME
};

/// <summary>
/// シーンの基底クラス
/// </summary>
class Scene_Base {
protected:
	/// <summary>
	/// メンバ変数
	/// </summary>

	static SceneNo sceneNo_;
public:
	/// <summary>
	/// メンバ関数
	/// </summary>

	// コンストラクタ
	Scene_Base() {}

	// 仮想デストラクタ
	virtual ~Scene_Base() {}

	// 純粋仮想関数
	virtual void Init() = 0;
	virtual void Update(char* keys, char* preKeys) = 0;
	virtual void Draw() = 0;

	SceneNo GetSceneNo() { return sceneNo_; }
};