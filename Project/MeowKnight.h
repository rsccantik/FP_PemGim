#include "Sprite.h"
#include "Character.h"
#include "Input.h"

#ifndef MEOWKNIGHT_H
#define MEOWKNIGHT_H

namespace Engine {
	class MeowKnight :public Engine::Character
	{
	public:
		MeowKnight(Texture* texture, Shader* shader, Quad* quad);
		~MeowKnight();
		void Update(float deltaTime);
		void Init(Input* inputManager);
	private:
		void Move(float deltaTime);
		Input* inputManager;
		float yVelocity;
		bool jump;
		float gravity;
	};
}
#endif
