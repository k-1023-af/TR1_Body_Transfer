#include "Bird.h"

Bird::Bird() {}
Bird::~Bird() {}

void Bird::Initialize(Vector3 startPos) {
	//Entity::Initialize(startPos);
	transform_.translate_ = startPos;

	width_ = 32.0f;
	height_ = 32.0f;
	acceleration_ = 16.0f;
	gravity_ = 1.8f;

	birdHandles_[0] = Novice::LoadTexture("./NoviceResources/Bird0.png");
	birdHandles_[1] = Novice::LoadTexture("./NoviceResources/Bird1.png");

	screenPos_.x = transform_.translate_.x;
	screenPos_.y = 720.0f - (transform_.translate_.y);
}

void Bird::AIUpdate(){
	velocity_ = { 0.0f, 0.0f };

	velocity_.x = (rand() % 5 - 2.0f);
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

	// Convert world position to screen position
	screenPos_.x = transform_.translate_.x;
	screenPos_.y = 720.0f - (transform_.translate_.y);
}

void Bird::Update(char* keys, char*preKeys) {
	velocity_ = { 0.0f, 0.0f };
	
	if (keys[DIK_SPACE]) {
		if (keys[DIK_A]) { velocity_.x -= 3.0f; }
		if (keys[DIK_D]) { velocity_.x += 3.0f; }
	}	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) { velocity_.y += acceleration_;  transform_.translate_.y += acceleration_; }
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

	// Convert world position to screen position
	screenPos_.x = transform_.translate_.x;
	screenPos_.y = 720.0f - (transform_.translate_.y);
}

void Bird::Draw() {
	if (velocity_.y > 0) {
		Novice::DrawSprite((int)screenPos_.x, (int)screenPos_.y, birdHandles_[1], 1.0f, 1.0f, 0.0f, WHITE);
	}
	else {
		Novice::DrawSprite((int)screenPos_.x, (int)screenPos_.y, birdHandles_[0], 1.0f, 1.0f, 0.0f, WHITE);
	}

	Novice::DrawBox((int)screenPos_.x, (int)screenPos_.y, (int)width_, (int)height_, 0.0f, RED, kFillModeWireFrame);
}