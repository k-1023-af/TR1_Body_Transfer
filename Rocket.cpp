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

void Rocket::Update(char* keys, char* preKeys) {
	(void)preKeys;
	velocity_ = { 0.0f, 0.0f };

	//if (keys[DIK_W]) { velocity_.y += 1.0f; }
	//if (keys[DIK_S]) { velocity_.y -= 1.0f; }
	if (keys[DIK_A]) { velocity_.x -= 1.0f; }
	if (keys[DIK_D]) { velocity_.x += 1.0f; }

	if (keys[DIK_SPACE]) { velocity_.y += acceleration_; }
	else { velocity_.y -= gravity_; }

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

void Rocket::Draw() {
	if (velocity_.y > 0.0f) {
		Novice::DrawSprite((int)screenPos_.x, (int)screenPos_.y, rocketHandles_[1], 1.0f, 1.0f, 0.0f, WHITE);
	}
	else {
		Novice::DrawSprite((int)screenPos_.x, (int)screenPos_.y, rocketHandles_[0], 1.0f, 1.0f, 0.0f, WHITE);
	}
	Novice::DrawBox((int)screenPos_.x, (int)screenPos_.y, (int)width_, (int)height_, 0, RED, kFillModeWireFrame);
}
