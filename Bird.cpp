#include "Bird.h"

Bird::Bird() {}
Bird::~Bird() {}

void Bird::Initialize(Vector3 startPos) {
	Entity::Initialize(startPos);
	speed_ = 3.5f;
}

void Bird::Update(char* keys) {
	(void)keys;

	//velocity_ = { 0.0f, 0.0f };
	//
	//if (keys[DIK_W]) { velocity_.y += 1.0f; }
	//if (keys[DIK_S]) { velocity_.y -= 1.0f; }
	//if (keys[DIK_A]) { velocity_.x -= 1.0f; }
	//if (keys[DIK_D]) { velocity_.x += 1.0f; }
	//
	//velocity_.x = (rand() % 3 - 1) * speed_;
	//velocity_.y = (rand() % 3 - 1) * speed_;

	float length = sqrtf(powf(velocity_.x, 2) + powf(velocity_.y, 2));
	if (length != 0) {
		velocity_.x = velocity_.x / length;
		velocity_.y = velocity_.y / length;

		transform_.translate_.x += velocity_.x;
		transform_.translate_.y += velocity_.y;
	}
	//Boundary check
	transform_.translate_.x = std::clamp(transform_.translate_.x, 50.0f, 1200.0f);
	transform_.translate_.y = std::clamp(transform_.translate_.y, 50.0f, 650.0f);

	screenPos_.x = transform_.translate_.x;
	screenPos_.y = 720 - transform_.translate_.y;
}

void Bird::Draw(char* keys) {
	(void)keys;

	//DrawControls(keys);
	Novice::DrawTriangle(
		(int)screenPos_.x, (int)screenPos_.y - 15,
		(int)screenPos_.x - 15, (int)screenPos_.y + 10,
		(int)screenPos_.x + 15, (int)screenPos_.y + 10,
		WHITE, kFillModeSolid
	);

	Novice::DrawLine(
		(int)screenPos_.x, (int)screenPos_.y,
		(int)(screenPos_.x + velocity_.x * 25),
		(int)(screenPos_.y + velocity_.y * 25),
		0xAAAAAAFF
	);
}