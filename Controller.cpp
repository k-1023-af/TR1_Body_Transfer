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
    rocket_->Initialize({ 400.0f, 200.0f, 0.0f });

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

    if (controlling != BIRD) {
        for (size_t i = 0; i < birds_.size(); ++i) {
            birds_[i]->AIUpdate();
        }
    }
    if (controlling != ROCKET) {
        rocket_->AIUpdate();
    }

    switch (controlling) {
    case PLAYER:
        player_->Update(keys, preKeys);
        camera_->translation_ = player_->GetTransform();

        if (keys[DIK_W] && !preKeys[DIK_W]) {

            if (player_->DistanceTo(rocket_) < 40.0f) {
                controlling = ROCKET;
                break;
            }
            // Check nearest Bird
            for (size_t i = 0; i < birds_.size(); ++i) {
                if (player_->DistanceTo(birds_[i]) < 80.0f) {
                    controlling = BIRD;
                    currentBirdIndex_ = static_cast<int>(i);
                    break;
                }
            }
        }
        break;

    case BIRD:
        if (!birds_.empty()) {
            Bird* activeBird = birds_[currentBirdIndex_];

            for (size_t i = 0; i < birds_.size(); ++i) {
                bool isControlled = (i == currentBirdIndex_);

                if (isControlled) {
                    birds_[i]->Update(keys, preKeys);
                }
                else {
                    birds_[i]->AIUpdate();
                }
            }

            player_->SetTransform(activeBird->GetTransform());

            Vector3 targetPos = activeBird->GetTransform();
            camera_->translation_.x = camera_->translation_.x * 0.85f + targetPos.x;
            camera_->translation_.y = camera_->translation_.y * 0.85f + targetPos.y;
            camera_->translation_.z = targetPos.z;
        }
        if (keys[DIK_W] && !preKeys[DIK_W]) {
            if (!birds_.empty()) {
                currentBirdIndex_ = (currentBirdIndex_ + 1) % birds_.size();
            }
        }

        if (keys[DIK_S] && !preKeys[DIK_S]) {
            controlling = PLAYER;
        }
        ////spawn bird
        //if (keys[DIK_B] && !preKeys[DIK_B]) {
        //    SpawnBird({
        //        static_cast<float>(rand() % 1000 + 100),
        //        static_cast<float>(rand() % 550 + 100),
        //        0.0f
        //        });
        //}

        break;

    case ROCKET:
        rocket_->Update(keys, preKeys);
        player_->SetTransform(rocket_->GetTransform());

        camera_->translation_ = rocket_->GetTransform();

        if (keys[DIK_S] && !preKeys[DIK_S]) {
            controlling = PLAYER;
        }
        break;
    }
}

void Controller::Draw() {
    for (Bird* bird : birds_) {
        bird->Draw();
    }
    rocket_->Draw();

    switch (controlling) {
    case PLAYER:
        player_->Draw();
        Novice::ScreenPrintf(10, 300, "Controlling : PLAYER");
        Novice::ScreenPrintf(10, 180, "A = Left | D = Right");
        Novice::ScreenPrintf(10, 210, "SPACE = Jump");
        Novice::ScreenPrintf(10, 240, "W = Body Transfer");
        break;

    case BIRD:
        Novice::ScreenPrintf(10, 300, "Controlling : BIRD");
        Novice::ScreenPrintf(10, 330, "Controlling : BIRD %d / %d",
            currentBirdIndex_ + 1, (int)birds_.size());

        Novice::ScreenPrintf(10, 180, "SPACE = Flap Wings");
        Novice::ScreenPrintf(10, 210, "W = Switch Bird");
        Novice::ScreenPrintf(10, 240, "S = Back to Player");
        //Novice::ScreenPrintf(10, 400, "B = Spawn New Bird");
        break;

    case ROCKET:
        Novice::ScreenPrintf(10, 300, "Controlling : ROCKET");
        Novice::ScreenPrintf(10, 180, "A = Left | D = Right");
        Novice::ScreenPrintf(10, 210, "SPACE = Boost");
        Novice::ScreenPrintf(10, 240, "S = Back to Player");
        break;
    }
}

Vector3 Controller::GetCameraPosition() const {
    return camera_ ? camera_->translation_ : Vector3{ 0,0,0 };
}

Vector2 Controller::GetCurrentVelocity() const {
    switch (controlling) {
    case PLAYER:
        return player_ ? player_->GetVelocity() : Vector2{ 0,0 };
    case BIRD:
        if (!birds_.empty()) {
            return birds_[currentBirdIndex_]->GetVelocity();
        }
        break;
    case ROCKET:
        return rocket_ ? rocket_->GetVelocity() : Vector2{ 0,0 };
    }
    return { 0.0f, 0.0f };
}


