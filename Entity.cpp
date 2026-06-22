#include "Entity.h"


void Entity::Initialize(Vector3 startPos) {
	transform_.translate_ = startPos;

	transform_.scale_ = { 1.0f, 1.0f, 1.0f };
	transform_.rotate_ = { 0.0f,0.0f,0.0f };
	velocity_ = { 0.0f,0.0f };
	screenPos_ = { startPos.x, 720.0f - startPos.y };
}

void Entity::DrawControls(char* keys) const {
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
}