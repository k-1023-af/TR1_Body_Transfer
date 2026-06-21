#include "Controller.h"

Controller::Controller(){}

Controller::~Controller(){}

void Controller::Initialize(KamataEngine::Camera* camera) {
	camera_ = camera;
	if (camera_) {
		camera_->rotation_ = { 0.0f, 0.0f, 0.0f };
	}
	
	player_ = new Player();
	player_->Initialize();
}

void Controller::Update(char* keys, char* preKeys) {
	Vector3 cameraTransform = player_->GetTransform();

	camera_->translation_.x = cameraTransform.x;
	camera_->translation_.y = cameraTransform.y;
	camera_->translation_.z = cameraTransform.z;

	switch (controlling){
	case PLAYER:
		cameraTransform = player_->GetTransform();
		player_->Update(keys);
		if (keys[DIK_T] && !preKeys[DIK_T]) {
			controlling = ROCKET;
		}
		break;
	case ROCKET:
		//cameraTransform = rocket_->GetTransform();
		if (keys[DIK_T] && !preKeys[DIK_T]) {
			controlling = BIRD;
		}
		break;
	case BIRD:
		//cameraTransform = bird_->GetTransform();
		if (keys[DIK_T] && !preKeys[DIK_T]) {
			controlling = PLAYER;
		}
		break;
	//case DEFAULT:
	//	break;
	}
}

void Controller::Draw(char* keys/*, char* preKeys*/) {

	switch (controlling){
	case PLAYER:
		player_->Draw(keys);
		Novice::ScreenPrintf(10, 130, "Controlling : PLAYER");
		break;
	case ROCKET:
		//car_->Draw(keys);
		Novice::ScreenPrintf(10, 130, "Controlling : ROCKET");

		break;

	case BIRD:
		//bird_->Draw(keys);
		Novice::ScreenPrintf(10, 130, "Controlling : BIRD");

		break;
	//case DEFAULT:
	//	break;
	}

	
	//if (keys[DIK_W]) {
	//	Novice::DrawBox(10, 30, 20, 20, 0, WHITE, kFillModeSolid);
	//}
	//if (keys[DIK_S]) {
	//	Novice::DrawBox(10, 60, 20, 20, 0, WHITE, kFillModeSolid);
	//
	//}
	//if (keys[DIK_A]) {
	//	Novice::DrawBox(40, 60, 20, 20, 0, WHITE, kFillModeSolid);
	//
	//}
	//if (keys[DIK_D]) {
	//	Novice::DrawBox(70, 60, 20, 20, 0, WHITE, kFillModeSolid);
	//}
	//if (keys[DIK_SPACE]) {
	//	Novice::DrawBox(10, 90, 20, 20, 0, WHITE, kFillModeSolid);
	//}
	//
	//Novice::ScreenPrintf(10,10, "Controls : WASD + SPACE");
}
