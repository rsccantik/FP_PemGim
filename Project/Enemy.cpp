#include "Enemy.h"
#include "Game.h"
#include "Texture.h"

Engine::Enemy::Enemy(Texture* texture, Shader* shader, Quad* quad) :Character(texture, shader, quad)
{
	sprite->SetNumXFrames(12);
	sprite->SetNumYFrames(1);
	sprite->AddAnimation("bot-die", 0, 5);
	sprite->AddAnimation("bot-up", 6, 11);
	sprite->AddAnimation("bot-upright", 6, 11);
	sprite->AddAnimation("bot-right", 6, 11);
	sprite->AddAnimation("bot-downright", 6, 11);
	sprite->AddAnimation("bot-down", 6, 11);
	sprite->AddAnimation("bot-downleft", 6, 11);
	sprite->AddAnimation("bot-left", 6, 11);
	sprite->AddAnimation("bot-upleft", 6, 11);
	sprite->AddAnimation("bot-down", 6, 11);
	
	sprite->SetScale(0.5);
	sprite->SetAnimationDuration(120);

	maxSpeed = 0.0f;
	target = NULL;
}

Engine::Enemy::~Enemy()
{
}


void Engine::Enemy::Update(float deltaTime)
{
	if (Engine::CharacterState::ALIVE == state) {
		Move(deltaTime);
	}

	vec2 p1 = sprite->GetPosition();
	vec2 p2 = p1 + vec2(sprite->GetScaleWidth(), 0.0f);
	vec2 p3 = p1 + vec2(sprite->GetScaleWidth(), sprite->GetScaleHeight());
	vec2 p4 = p1 + vec2(0.0f, sprite->GetScaleHeight());
	boundingBox.SetVertices(p1, p2, p3, p4);

}

void Engine::Enemy::SetTarget(Character* target)
{
	this->target = target;
}

void Engine::Enemy::SetMaxSpeed(float maxSpeed)
{
	this->maxSpeed = maxSpeed;
}

void Engine::Enemy::Move(float deltaTime)
{
	vec2 steering = Seek();

	// Update Bot Position based on steering behavior
	velocity += steering;
	vec2 position = GetPosition();
	vec2 oldPosition = vec2(position);
	position += velocity * deltaTime;
	SetPosition(position.x, position.y);

	// Update Sprite Animation
	string anim = FacingSprite(oldPosition, position);
	if (anim.empty()) {
		anim = "up"; // Default animasi jika tidak ada perubahan arah
	}
	sprite->PlayAnim("bot-" + anim);
	sprite->Update(deltaTime);
}

vec2 Engine::Enemy::Seek() {
	vec2 targetPosition = target->GetPosition();
	vec2 position = GetPosition();
	vec2 desiredVelocity = normalize(targetPosition - position) * maxSpeed;
	vec2 steering = desiredVelocity - velocity;
	return steering;
}

string Engine::Enemy::FacingSprite(vec2 position, vec2 target)
{
	vec2 direction = normalize(target - position);

	float angle = degrees(atan2(direction.y, direction.x));
	if (angle < 0) {
		angle += 360;
	}

	float range = 20.0f;

	if (angle >= (0.0f + range) && angle < (45.0f + range)) {
		return "upright";
	}
	else if (angle >= (45.0f + range) && angle < (90.0f + range)) {
		return "up";
	}
	else if (angle >= (90.0f + range) && angle < (135.0f + range)) {
		return "upleft";
	}
	else if (angle >= (135.0f + range) && angle < (180.0f + range)) {
		return "left";
	}
	else if (angle >= (180.0f + range) && angle < (235.5f + range)) {
		return "downleft";
	}
	else if (angle >= (235.5f + range) && angle < (270.0f + range)) {
		return "down";
	}
	else if (angle >= (270.0f + range) && angle < (300.0f + range)) {
		return "downright";
	}
	else {
		return "right";
	}
}