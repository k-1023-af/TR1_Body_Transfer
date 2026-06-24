#include "Rocket.h"

Rocket::Rocket() {}

Rocket::~Rocket() {}

void Rocket::Initialize(Vector3 startPos) {
	transform_.translate_ = startPos;

	width_ = 32.0f;
	height_ = 64.0f;

	velocity_ = { 0.0f, 0.0f };
	gravity_ = 0.8f;
	acceleration_ = 4.0f;

	rocketHandles_[0] = Novice::LoadTexture("./NoviceResources/Rocket0.png");
	rocketHandles_[1] = Novice::LoadTexture("./NoviceResources/Rocket1.png");

	screenPos_.x = transform_.translate_.x;
	screenPos_.y = 720.0f - (transform_.translate_.y);
}

void Rocket::AIUpdate(){
	velocity_ = { 0.0f, 0.0f };
	velocity_.y -= gravity_;

	GlobalUpdateLogic();
}

void Rocket::Update(char* keys, char* preKeys) {
	(void)preKeys;
	velocity_ = { 0.0f, 0.0f };

	if (keys[DIK_A]) { velocity_.x -= 1.0f; }
	if (keys[DIK_D]) { velocity_.x += 1.0f; }

	if (keys[DIK_SPACE]) { velocity_.y += acceleration_; }
	else { velocity_.y -= gravity_; }

	GlobalUpdateLogic();
}

void Rocket::Draw() {
	if (velocity_.y > 0.0f) {
		Novice::DrawSprite((int)screenPos_.x, (int)screenPos_.y, rocketHandles_[1], 1.0f, 1.0f, 0.0f, WHITE);
	}
	else {
		Novice::DrawSprite((int)screenPos_.x, (int)screenPos_.y, rocketHandles_[0], 1.0f, 1.0f, 0.0f, WHITE);
	}
	Novice::DrawBox((int)screenPos_.x, (int)screenPos_.y, (int)width_, (int)height_, 0, RED, kFillModeWireFrame);
}
