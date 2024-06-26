#ifndef NPCWAVE_H
#define NPCWAVE_H

#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Enemy.h"
#include "MeowKnight.h"
#include <random> 

namespace Engine {
	class NPCWave :public Engine::Game
	{
	public:
		NPCWave(Setting* setting);
		~NPCWave();
		void Init() override;
		void Update() override;
		void Render() override;
	private:
		Texture* texture;
		Texture* texture2;
		float spawnTimer;
		MeowKnight* hero;
        std::vector<Enemy*> enemies;
	};
}
#endif