#pragma once
#include "KamataEngine.h"
#include "Novice.h"
#include <algorithm>

using namespace KamataEngine;

class Entity{
public:
	virtual ~Entity() = default;

	virtual void Initialize(Vector3 startPos = { 0,0,0 });
	virtual void Update(char* keys) = 0;
	virtual void Draw(char* keys) = 0;

	Vector3 GetTransform() const { return transform_.translate_; }
	Vector3 GetPosition() const { return transform_.translate_; }

	void DrawControls(char* keys) const;

protected:
	struct Transform {
		Vector3 scale_ = { 1.0f, 1.0f, 1.0f };
		Vector3 rotate_ = { 0.0f, 0.0f, 0.0f };
		Vector3 translate_ = { 0.0f, 0.0f, 0.0f };
	};

	Transform transform_;
	Vector2 screenPos_;
	Vector2 velocity_ = { 0.0f, 0.0f };
};

