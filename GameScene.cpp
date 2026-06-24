#include "GameScene.h"
#include <cmath>

GameScene::GameScene() {}
GameScene::~GameScene() {
	delete controller_;
	delete camera_;
}
void GameScene::Initialize() {
	camera_ = new KamataEngine::Camera();

	controller_ = new Controller(); 
	controller_->Initialize(camera_);

	bgHandle_ = Novice::LoadTexture("./NoviceResources/Quiet_Winter.png");
}
void GameScene::Update(char* keys, char* preKeys) {
	controller_->Update(keys, preKeys);
}
void GameScene::Draw(char* keys) {

    //Vector3 cameraPosition;
    //cameraPosition = controller_->GetCameraPosition();

    Vector2 currentVelocity;
    currentVelocity = controller_->GetCurrentVelocity();

    Novice::DrawSprite(0 - (int)currentVelocity.x, 0, bgHandle_, 1, 1, 0, WHITE);
    Novice::DrawSprite(1280 - (int)currentVelocity.x, 0, bgHandle_, 1, 1, 0, WHITE);
    Novice::DrawSprite(-1280 - (int)currentVelocity.x, 0, bgHandle_, 1, 1, 0, WHITE);

    entity_->DrawControls(keys);

    controller_->Draw();
}