#include "GameScene.h"

GameScene::GameScene() {}
GameScene::~GameScene() {
	delete controller_;
	delete camera_;
}
void GameScene::Initialize() {
	camera_ = new KamataEngine::Camera();

	controller_ = new Controller(); 
	controller_->Initialize(camera_);
}
void GameScene::Update(char* keys, char* preKeys) {
	controller_->Update(keys, preKeys);
}
void GameScene::Draw(char* keys) {
	controller_->Draw(keys);
}