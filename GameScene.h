#pragma once
#include "KamataEngine.h"
#include "Player.h"
#include "Controller.h"
#include "Novice.h"
#include "Entity.h"

class GameScene {
public:
	GameScene();
	~GameScene();
	void Initialize();
	void Update(char* keys, char* preKeys);
	void Draw(char* keys);

private:
	Controller* controller_;

	Entity* entity_ = nullptr;

	KamataEngine::Camera* camera_ = nullptr;

	int bgHandle_;

	float bgScrollX_ = 0.0f;
	float scrollSpeed_ = 0.8f;
};

