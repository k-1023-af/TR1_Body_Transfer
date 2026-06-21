#include <Novice.h>
#include <Windows.h>
//#include "KamataEngine.h"
#include "GameScene.h"
#include "Player.h"
#include "Controller.h"
//#include "imgui.h"
#include "2d/ImGuiManager.h"

//using namespace KamataEngine;

//DirectXCommon* dxCommon = DirectXCommon::GetInstance();

GameScene* gameScene = new GameScene();

//Player* player = new Player();

//Controller* control = new Controller();

const char kWindowTitle[] = "LE2C_21_ファルコン_エブラハム";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	gameScene->Initialize();

	//player->Initialize();
	//control->Initialize();

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
#ifdef USE_IMGUI
//ImGuiManager* imguiManager = ImGuiManager::GetInstance();

//imguiManager->Begin();

	gameScene->Update(keys, preKeys);

		//ImGui::ShowDemoWindow();

	//player->Update(keys);
	//control->Update(keys, preKeys);

		//imguiManager->End();
#endif
///
/// ↑更新処理ここまで
///

///
/// ↓描画処理ここから
///
//dxCommon->PreDraw();


	gameScene->Draw(keys);

/// 軸表示の描画

//AxisIndicator::GetInstance()->Draw();

/// ImGuiの描画
//imguiManager->Draw();

		//player->Draw(keys);
		//control->Draw(keys);

		//scene->DrawDiceNet();

		//scene->DrawPipsOnFace();

		//dxCommon->PostDraw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete gameScene;

	//delete player;

	//delete control;

	gameScene = nullptr;

	//player = nullptr;

	//control = nullptr;



	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
