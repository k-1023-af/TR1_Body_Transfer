#include "Bird.h"

Bird::Bird() {}
Bird::~Bird() {}

void Bird::Initialize(Vector3 startPos) {
	transform_.translate_ = startPos;

	width_ = 32.0f;
	height_ = 32.0f;
	acceleration_ = 16.0f;
	gravity_ = 4.8f;

	birdHandles_[0] = Novice::LoadTexture("./NoviceResources/Bird0.png");
	birdHandles_[1] = Novice::LoadTexture("./NoviceResources/Bird1.png");

	screenPos_.x = transform_.translate_.x;
	screenPos_.y = 720.0f - (transform_.translate_.y);
}

void Bird::AIUpdate() {
	velocity_ = { 0.0f, 0.0f };
	
	kTimer--;
	if (kTimer <= 0){
		velocity_.x = (rand() % 20 - 8.0f);
		kTimer = 10;
	}
	velocity_.y -= gravity_;

	GlobalUpdateLogic();
}

void Bird::Update(char* keys, char*preKeys) {
	velocity_ = { 0.0f, 0.0f };
	
	if (keys[DIK_SPACE]) {
		if (keys[DIK_A]) { velocity_.x -= 3.0f; }
		if (keys[DIK_D]) { velocity_.x += 3.0f; }
	}	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) { velocity_.y += acceleration_;  transform_.translate_.y += acceleration_; }
	velocity_.y -= gravity_;
	
	GlobalUpdateLogic();
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