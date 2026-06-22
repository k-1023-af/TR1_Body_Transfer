#include "Player.h"

Player::Player(){}

Player::~Player(){}

void Player::Initialize(Vector3 startPos){
	transform_.translate_ = startPos;

	velocity_ = { 0.0f, 0.0f};

	gravity_ = 0.8f;
	jumpHeight_ = 12.0f;
}

void Player::Update(char* keys){
	velocity_ = { 0.0f, 0.0f };

	if (keys[DIK_W]) {velocity_.y += 1.0f;}
	if (keys[DIK_S]) {velocity_.y -= 1.0f;}
	if (keys[DIK_A]) {velocity_.x -= 1.0f;}
	if (keys[DIK_D]) {velocity_.x += 1.0f;}

	float length = sqrtf(powf(velocity_.x, 2) + powf(velocity_.y, 2));
	if (length != 0) {
		velocity_.x = velocity_.x / length;
		velocity_.y = velocity_.y / length;

		transform_.translate_.x += velocity_.x;
		transform_.translate_.y += velocity_.y;
	}

	screenPos_.x = transform_.translate_.x;
	screenPos_.y = 720 - transform_.translate_.y;
}

void Player::Draw(char* keys){
	DrawControls(keys);

	Novice::DrawBox((int)screenPos_.x, (int)screenPos_.y, 20, 20, 0, WHITE, kFillModeSolid);

	Novice::ScreenPrintf(10, 10, "Controls : WASD + SPACE");
}
