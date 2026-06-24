#include "Entity.h"


void Entity::Initialize(Vector3 startPos) {
	transform_.translate_ = startPos;

	transform_.scale_ = { 1.0f, 1.0f, 1.0f };
	transform_.rotate_ = { 0.0f,0.0f,0.0f };
	transform_.translate_ = { 0.0f, 0.0f, 0.0f };
	velocity_ = { 0.0f,0.0f };
}

float Entity::DistanceTo(const Entity* other) const {
	if (!other) return 999999.0f;

	Vector3 a = transform_.translate_;
	Vector3 b = other->GetTransform();

	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;

	return sqrtf(dx * dx + dy * dy + dz * dz);
}

void Entity::DrawControls(char* keys) const {
	Novice::DrawBox(60, 32, 40, 40, 0, WHITE, kFillModeWireFrame);
	Novice::ScreenPrintf(78, 32, "W");
	Novice::DrawBox(10, 80, 40, 40, 0, WHITE, kFillModeWireFrame);
	Novice::ScreenPrintf(28, 82, "A");
	Novice::DrawBox(60, 80, 40, 40, 0, WHITE, kFillModeWireFrame);
	Novice::ScreenPrintf(78, 82, "S");
	Novice::DrawBox(110, 80, 40, 40, 0, WHITE, kFillModeWireFrame);
	Novice::ScreenPrintf(128, 82, "D");

	//Novice::DrawBox(180, 30, 40, 40, 0, WHITE, kFillModeWireFrame);
	//Novice::ScreenPrintf(196, 32, "T");
	//Novice::DrawBox(180, 80, 40, 40, 0, WHITE, kFillModeWireFrame);
	//Novice::ScreenPrintf(196, 82, "B");


	Novice::DrawBox(10, 130, 140, 30, 0, WHITE, kFillModeWireFrame);
	Novice::ScreenPrintf(48, 132, "SPACE");

	if (keys[DIK_W]) {
		Novice::DrawBox(60, 30, 40, 40, 0, WHITE, kFillModeSolid);
	}
	if (keys[DIK_A]) {
		Novice::DrawBox(10, 80, 40, 40, 0, WHITE, kFillModeSolid);
	}
	if (keys[DIK_S]) {
		Novice::DrawBox(60, 80, 40, 40, 0, WHITE, kFillModeSolid);
	}
	if (keys[DIK_D]) {
		Novice::DrawBox(110, 80, 40, 40, 0, WHITE, kFillModeSolid);
	}
	if (keys[DIK_SPACE]) {
		Novice::DrawBox(10, 130, 140, 30, 0, WHITE, kFillModeSolid);
	}
	//if (keys[DIK_T]) {
	//	Novice::DrawBox(180, 30, 40, 40, 0, WHITE, kFillModeSolid);
	//}
	//if (keys[DIK_B]) {
	//	Novice::DrawBox(180, 80, 40, 40, 0, WHITE, kFillModeSolid);
	//}


}