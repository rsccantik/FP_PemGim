#include "MeowKnight.h"

Engine::MeowKnight::MeowKnight(Texture* texture, Shader* shader, Quad* quad) :Character(texture, shader, quad)
{
	sprite->SetNumXFrames(37); // Set the number of frames horizontally
	sprite->SetNumYFrames(1);  // Set the number of frames vertically
	sprite->AddAnimation("run", 0, 6);       // Frames for run animation
	sprite->AddAnimation("idle", 7, 12);     // Frames for idle animation
	sprite->AddAnimation("jump", 13, 22);    // Frames for jump animation
	sprite->AddAnimation("attack", 23, 32);  // Frames for attack animation
	sprite->AddAnimation("death", 33, 37);   // Frames for death animation
	sprite->PlayAnim("idle");                // Start with idle animation
	sprite->SetScale(3);                     // Set scale of the sprite
	sprite->SetAnimationDuration(90);        // Set animation duration

	inputManager = NULL;
	yVelocity = 0.0f;  // Initialize yVelocity
	jump = false;      // Initialize jump state
}

Engine::MeowKnight::~MeowKnight()
{

}

void Engine::MeowKnight::Update(float deltaTime)
{
	if (Engine::CharacterState::ALIVE == state) {
		Move(deltaTime);
	}
}


void Engine::MeowKnight::Move(float deltaTime)
{
	// Get Current Player's Position
	vec2 oldSpritePos = sprite->GetPosition();
	float x = oldSpritePos.x, y = oldSpritePos.y;
	float speed = 0.07f;

	// s = v * t;
	// Control player's movement using keyboard or gamepad
	velocity = vec2(0, 0);
	string anim = "";

	if (inputManager->IsKeyPressed("run-right")) {
		velocity.x += speed;
		sprite->SetFlipHorizontal(false);
		anim = "run";
	}

	if (inputManager->IsKeyPressed("run-left")) {
		velocity.x -= speed;
		sprite->SetFlipHorizontal(true);
		anim = "run";
	}

	if (inputManager->IsKeyPressed("run-up")) {
		velocity.y += speed;
		anim = "run";
	}

	if (inputManager->IsKeyPressed("run-down")) {
		velocity.y -= speed;
		anim = "run";
	}

	if (inputManager->IsKeyPressed("Jump") && !jump) {
		// Set gravity and yVelocity
		float ratio = (deltaTime / 16.7f);
		gravity = 0.16f * ratio;
		yVelocity = 1.8f;
		jump = true;
		anim = "jump";
	}

	if (y > 0) {
		yVelocity -= gravity;
	}
	else if (y <= 0) {
		jump = false;
		yVelocity = 0;
		y = 0;
	}

	y += yVelocity * deltaTime;

	if (inputManager->IsKeyPressed("attack")) {
		anim = "attack";
	}



	// Update new player's position
	vec2 newPosition = vec2(x, y) + velocity * deltaTime;
	sprite->SetPosition(newPosition.x, newPosition.y);
	
	// Update player's animation
	sprite->PlayAnim(anim);
	sprite->Update(deltaTime);

}

void Engine::MeowKnight::Init(Input* inputManager)
{
	this->inputManager = inputManager;

	// run
	inputManager->AddInputMapping("run-left", SDLK_a);
	inputManager->AddInputMapping("run-right", SDLK_d);
	// run up and down
	inputManager->AddInputMapping("run-up", SDLK_w);
	inputManager->AddInputMapping("run-down", SDLK_s);
	// attack
	inputManager->AddInputMapping("attack", SDL_MOUSEBUTTONDOWN);
	// jump
	inputManager->AddInputMapping("jump", SDLK_SPACE);
}
