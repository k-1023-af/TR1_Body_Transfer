#include "Player.h"

Player::Player(){}

Player::~Player(){}

void Player::Initialize(){
	srt.scale_ = { 1.0f, 1.0f, 0.0f };
	srt.rotate_ = {0.0f, 0.0f, 0.0f };
	srt.translate_ = { 100.0f, 100.0f, 0.0f };

	velocity_ = { 0.0f, 0.0f};

	gravity_ = 0.8f;
	jumpHeight_ = 12.0f;
}

void Player::Update(char* keys/*, char* preKeys*/){
	velocity_ = { 0.0f, 0.0f };

	if (keys[DIK_W]) {
		velocity_.y++;
	}
	if (keys[DIK_S]) {
		velocity_.y--;
	}
	if (keys[DIK_A]) {
		velocity_.x--;
	}
	if (keys[DIK_D]) {
		velocity_.x++;
	}

	float length = sqrtf(powf(velocity_.x, 2) + powf(velocity_.y, 2));
	if (length != 0) {
		velocity_.x = velocity_.x / length;
		velocity_.y = velocity_.y / length;

		srt.translate_.x += velocity_.x;
		srt.translate_.y += velocity_.y;
	}
}

void Player::Draw(char* keys/*, char* preKeys*/){
	Novice::DrawBox(40, 30, 20, 20, 0, WHITE, kFillModeWireFrame);
	Novice::ScreenPrintf(48, 30, "W");
	Novice::DrawBox(10, 60, 20, 20, 0, WHITE, kFillModeWireFrame);
	Novice::ScreenPrintf(18, 60, "A");
	Novice::DrawBox(40, 60, 20, 20, 0, WHITE, kFillModeWireFrame);
	Novice::ScreenPrintf(48, 60, "S");
	Novice::DrawBox(70, 60, 20, 20, 0, WHITE, kFillModeWireFrame);
	Novice::ScreenPrintf(78, 60, "D");
	Novice::DrawBox(10, 90, 80, 20, 0, WHITE, kFillModeWireFrame);
	Novice::ScreenPrintf(28, 90, "SPACE");

	if (keys[DIK_W]) {
		Novice::DrawBox(40, 30, 20, 20, 0, WHITE, kFillModeSolid);
	}
	if (keys[DIK_A]) {
		Novice::DrawBox(10, 60, 20, 20, 0, WHITE, kFillModeSolid);
	}
	if (keys[DIK_S]) {
		Novice::DrawBox(40, 60, 20, 20, 0, WHITE, kFillModeSolid);
	}
	if (keys[DIK_D]) {
		Novice::DrawBox(70, 60, 20, 20, 0, WHITE, kFillModeSolid);
	}
	if (keys[DIK_SPACE]) {
		Novice::DrawBox(10, 90, 80, 20, 0, WHITE, kFillModeSolid);
	}

	Novice::ScreenPrintf(10, 10, "Controls : WASD + SPACE");
}
