#ifndef LESSON11_PARALLAXSCROLLING_H
#define LESSON01_PARALLAXSCROLLING_H

#include "Game.h"
#include "Setting.h"
#include <vector>
#include "Sprite.h"

namespace Engine {
	class ParallaxScrolling :public Engine::Game
	{
	public:
		ParallaxScrolling(Setting* setting);
		~ParallaxScrolling();
		virtual void Init();
		virtual void Update();
		virtual void Render();
	private:
		vector<Sprite*> backgrounds, middlegrounds, foregrounds;
		void MoveLayer(vector<Sprite*>& bg, float speed);
		void DrawLayer(vector<Sprite*>& bg);
		void AddToLayer(vector<Sprite*>& bg, string name);
		float offset = 0;
	};
}

#endif

