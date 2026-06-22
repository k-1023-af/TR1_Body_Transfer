#include "Controller.h"
#include <ctime>

Controller::Controller() {}

Controller::~Controller() {
    delete player_;
    for (Bird* bird : birds_) {
        delete bird;
    }
    birds_.clear();
}

void Controller::Initialize(KamataEngine::Camera* camera) {
    camera_ = camera;
    if (camera_) {
        camera_->rotation_ = { 0.0f, 0.0f, 0.0f };
    }

    // Initialize random seed
    srand(static_cast<unsigned int>(time(nullptr)));

    player_ = new Player();
    player_->Initialize({ 100.0f, 100.0f, 0.0f });

    rocket_ = new Rocket();
    rocket_->Initialize(player_->GetPosition());

    // Spawn several birds
    SpawnBird({ 300.0f, 200.0f, 0.0f });
    SpawnBird({ 600.0f, 400.0f, 0.0f });
    SpawnBird({ 900.0f, 150.0f, 0.0f });
    SpawnBird({ 450.0f, 550.0f, 0.0f });
    SpawnBird({ 750.0f, 300.0f, 0.0f });
}

void Controller::SpawnBird(Vector3 startPos) {
    Bird* newBird = new Bird();
    newBird->Initialize(startPos);
    birds_.push_back(newBird);
}

void Controller::Update(char* keys, char* preKeys) {
    switch (controlling) {
    case PLAYER:
        player_->Update(keys);

        // Camera follows player
        {
            Vector3 pos = player_->GetTransform();
            camera_->translation_.x = pos.x;
            camera_->translation_.y = pos.y;
            camera_->translation_.z = pos.z;
        }

        if (keys[DIK_T] && !preKeys[DIK_T]) {
            controlling = BIRD;
        }
        break;

    case BIRD:
        // Update all birds
        for (Bird* bird : birds_) {
            bird->Update(keys);
        }

        // Camera follows current bird
        if (!birds_.empty()) {
            Bird* activeBird = birds_[currentBirdIndex_];
            Vector3 pos = activeBird->GetTransform();
            camera_->translation_.x = pos.x;
            camera_->translation_.y = pos.y;
            camera_->translation_.z = pos.z;
        }

        // Switch between birds
        if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
            if (!birds_.empty()) {
                currentBirdIndex_ = (currentBirdIndex_ + 1) % birds_.size();
            }
        }

        // Spawn new bird
        if (keys[DIK_B] && !preKeys[DIK_B]) {
            SpawnBird({
                static_cast<float>(rand() % 1000 + 100),
                static_cast<float>(rand() % 550 + 100),
                0.0f
                });
        }

        if (keys[DIK_T] && !preKeys[DIK_T]) {
            controlling = ROCKET;
        }
        break;

    case ROCKET:
        rocket_->Update(keys);

        {
            Vector3 pos = player_->GetTransform();
            camera_->translation_.x = pos.x;
            camera_->translation_.y = pos.y;
            camera_->translation_.z = pos.z;
        }

        if (keys[DIK_T] && !preKeys[DIK_T]) {
            controlling = PLAYER;
        }
        break;
    }
}

void Controller::Draw(char* keys) {
    switch (controlling) {
    case PLAYER:
        player_->Draw(keys);
        Novice::ScreenPrintf(10, 130, "Controlling : PLAYER");
        break;

    case BIRD:
        // Draw all birds
        for (Bird* bird : birds_) {
            bird->Draw(keys);
        }

        Novice::ScreenPrintf(10, 100, "Total Birds: %d", (int)birds_.size());
        Novice::ScreenPrintf(10, 130, "Controlling : BIRD %d / %d",
            currentBirdIndex_ + 1, (int)birds_.size());

        Novice::ScreenPrintf(10, 160, "SPACE = Switch Bird");
        Novice::ScreenPrintf(10, 180, "B = Spawn New Bird");
        Novice::ScreenPrintf(10, 200, "T = Back to Player");
        break;

    case ROCKET:
        rocket_->Draw(keys);

        Novice::ScreenPrintf(10, 130, "Controlling : ROCKET");
        break;
    }
}