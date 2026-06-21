#pragma once
#include "KamataEngine.h"
#include "Novice.h"
//#include "Controller.h"

using namespace KamataEngine;

class Player
{
public:
	Player();
	~Player();
	void Initialize();
	void Update(char* keys/*, char* preKeys*/);
	void Draw(char* keys/*, char* preKeys*/);

	Vector3 GetTransform() const { return srt.translate_; }


private:
	struct SRT {
		Vector3 scale_;
		Vector3 rotate_;
		Vector3 translate_;
	};

	SRT srt;
	
	Vector2 velocity_;
	float gravity_;
	float jumpHeight_;
};

