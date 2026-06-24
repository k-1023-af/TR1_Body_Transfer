#include "Player.h"

Player::Player(){}

Player::~Player(){}

void Player::Initialize(Vector3 startPos){
	transform_.translate_ = startPos;

	gravity_ = 1.8f;
	width_ = 32.0f;
	height_ = 64.0f;

	jumpHeight_ = 72.0f;

	playerHandle_ = Novice::LoadTexture("./NoviceResources/Char8.png");
}

void Player::Update(char* keys, char* preKeys){
	velocity_ = { 0.0f, 0.0f };

	if (keys[DIK_A]) {velocity_.x -= 15.0f;}
	if (keys[DIK_D]) {velocity_.x += 15.0f;}
	
	if ((transform_.translate_.y <= 128.0f + height_) && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) { transform_.translate_.y += jumpHeight_; }
	else { transform_.translate_.y -= gravity_; }

	UniversalUpdateChecks();
}

void Player::Draw(){

	Novice::DrawSprite((int)screenPos_.x, (int)screenPos_.y, playerHandle_, 1.0f, 1.0f, 0, WHITE);
	Novice::DrawBox((int)screenPos_.x, (int)screenPos_.y, (int)width_, (int)height_, 0, RED, kFillModeWireFrame);
}

void Player::SetTransform(const Vector3& newPos) {
	transform_.translate_ = newPos;
	screenPos_.x = newPos.x;
	screenPos_.y = 720.0f - newPos.y;
}
