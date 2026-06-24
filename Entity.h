#pragma once
#include "KamataEngine.h"
#include "Novice.h"
#include <algorithm>

using namespace KamataEngine;

class Entity{
public:
	virtual ~Entity() = default;

	virtual void Initialize(Vector3 startPos = { 0,0,0 });
	virtual void Update(char* keys, char* preKeys) = 0;
	virtual void Draw() = 0;

	Vector3 GetTransform() const { return transform_.translate_; }
	Vector2 GetVelocity() const { return velocity_; }

	void GlobalUpdateLogic();
	void DrawControls(char* keys) const;

	float DistanceTo(const Entity* other) const;

protected:
	struct Transform {
		Vector3 scale_ = { 1.0f, 1.0f, 1.0f };
		Vector3 rotate_ = { 0.0f, 0.0f, 0.0f };
		Vector3 translate_ = { 0.0f, 0.0f, 0.0f };
	};

	Transform transform_;
	Vector2 screenPos_;
	Vector2 velocity_;

	float gravity_;
	float acceleration_;
	float width_;
	float height_;
};

