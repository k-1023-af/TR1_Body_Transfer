#include "Player.h"

Player::Player(){}

Player::~Player(){}

void Player::Initialize(Vector3 startPos){
	transform_.translate_ = startPos;

	velocity_ = { 0.0f, 0.0f};

	gravity_ = 1.8f;
	jumpHeight_ = 72.0f;
	width_ = 32.0f;
	height_ = 64.0f;

	playerHandle_ = Novice::LoadTexture("./NoviceResources/Char8.png");
}

void Player::Update(char* keys, char* preKeys){
	velocity_ = { 0.0f, 0.0f };

	//if (keys[DIK_W]) {velocity_.y += 1.0f;}
	//if (keys[DIK_S]) {velocity_.y -= 1.0f;}
	if (keys[DIK_A]) {velocity_.x -= 15.0f;}
	if (keys[DIK_D]) {velocity_.x += 15.0f;}
	
	if ((transform_.translate_.y <= 128.0f + height_) && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) { transform_.translate_.y += jumpHeight_; }
	else { transform_.translate_.y -= gravity_; }

	float length = sqrtf(powf(velocity_.x, 2) + powf(velocity_.y, 2));
	if (length != 0) {
		velocity_.x = velocity_.x / length;
		velocity_.y = velocity_.y / length;

		transform_.translate_.x += velocity_.x;
		transform_.translate_.y += velocity_.y;
	}
	//Boundary check
	transform_.translate_.x = std::clamp(transform_.translate_.x, 50.0f, 1200.0f);
	transform_.translate_.y = std::clamp(transform_.translate_.y, 128.0f + height_, 650.0f);

	screenPos_.x = transform_.translate_.x;
	screenPos_.y = 720.0f - (transform_.translate_.y);
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
