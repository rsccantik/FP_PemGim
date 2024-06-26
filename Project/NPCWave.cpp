#include "NPCWave.h"
#include <iostream>


Engine::NPCWave::NPCWave(Setting* setting) :Engine::Game(setting)
{
	texture = NULL;
	texture2 = NULL;
	spawnTimer = 0.0f;
	hero = NULL;
	setting->windowTitle = "Wave";
}

Engine::NPCWave::~NPCWave()
{
	delete hero;
	delete texture;
	delete texture2;
	for (Enemy* enemy : enemies) {
		delete enemy;
	}
	enemies.clear();
}

void Engine::NPCWave::Init()
{
	texture = new Texture("Meow_Knight.png");
	texture2 = new Texture("S_all.png");
	SetBackgroundColor(209, 228, 231);
	hero = new MeowKnight(texture, defaultSpriteShader, defaultQuad);
	hero->Init(inputManager);
	hero->SetPosition(setting->screenWidth / 2.0f - hero->GetSprite()->GetScaleWidth(), setting->screenHeight / 2.0f);

}

void Engine::NPCWave::Update()
{
	if (inputManager->IsKeyPressed("quit")) {
		state = Engine::State::EXIT;
	}

	// Spawn Enemies
	spawnTimer += GetGameTime();
	if (spawnTimer >= 1000) {
		
		// create a new enemy
		Enemy* enemy = new Enemy(texture2, defaultSpriteShader, defaultQuad);
		
		// Set random enemy's position
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> disX(0, setting->screenWidth);
		float x = static_cast<float>(disX(gen));
		std::uniform_int_distribution<> disY(0, setting->screenHeight);
		float y = static_cast<float>(disY(gen));
		
		std::uniform_int_distribution<> disBorder(0, 3);
		int border = disBorder(gen);

		// 0 = spawn from bottom, 1 = left, 2 = top, 3 = right
		if (0 == border) {
			y = static_cast<float>(setting->screenHeight); // Spawn from bottom
		}
		else if (1 == border) {
			x = 0.0f; // Spawn from left
		}
		else if (2 == border) {
			y = 0.0f; // Spawn from top
		}
		else {
			x = static_cast<float>(setting->screenWidth); // Spawn from right
		}

		enemy->SetPosition(x, y);
		enemy->SetMaxSpeed(0.06f);
		enemy->SetTarget(hero);
		enemies.push_back(enemy);
		spawnTimer = 0;

		// Debug: Print enemy creation and position
		std::cout << "Enemy created at position (" << x << ", " << y << ")\n";
	}

	for (Enemy* e : enemies) {
		e->Update(GetGameTime());
	}

	hero->Update(GetGameTime());

}

void Engine::NPCWave::Render()
{
	for (Enemy* enemy : enemies) {
		enemy->Draw();
	}
	hero->Draw();
}

