#include <Novice.h>
#include "SceneManager.h"

const char kWindowTitle[] = "LC1B_28_ムラタ_サクヤ_PG2_STG_class_ET";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 768);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// シーン管理クラスのインスタンスの作成
	SceneManager* sceneManger_ = new SceneManager();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		// F11を押すとフルスクリーンになる
		if (keys[DIK_F11] && !preKeys[DIK_F11]) {

			Novice::SetWindowMode(WindowMode::kFullscreen);
		}

		sceneManger_->Run(keys, preKeys);

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {

			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();

	// 開放
	delete sceneManger_;

	return 0;
}
