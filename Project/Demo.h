//#ifndef DEMO_H
//#define DEMO_H
//
//#include "Game.h"
//#include "Setting.h"
//#include "Texture.h"
//#include "Sprite.h"
//#include "Music.h"
//#include "Sound.h"
//#include "Text.h"
//#include <vector>
//
//namespace Engine {
//	class Demo :
//		public Engine::Game
//	{
//	public:
//		Demo(Setting* setting);
//		~Demo();
//		virtual void Init();
//		virtual void Update();
//		virtual void Render();
//
//	private:
//		Texture* dotTexture = NULL;
//		vector<Sprite*> platforms;
//		Sprite* monsterSprite = NULL;
//		Sprite* charSprite = NULL;
//		Sprite* projectileSprite = NULL;
//		Sprite* Chara2 = NULL;
//		Sprite* death = NULL;
//		Sprite* backgroundSprite = NULL;
//		Sprite* dotSprite1 = NULL;
//		Sprite* dotSprite2 = NULL;
//		Sprite* dotSprite3 = NULL;
//		Sprite* dotSprite4 = NULL;
//
//		Sprite* dotProject1 = NULL;
//		Sprite* dotProject2 = NULL;
//		Sprite* dotProject3 = NULL;
//		Sprite* dotProject4 = NULL;
//		Music* music = NULL;;
//		Sound* sound = NULL;
//		Text* text = NULL;
//		float yVelocity = 0, gravity = 0;
//		bool jump = false, debug = false;
//		float mul = 1;
//		bool isProjectileActive = false;
//	};
//}
//#endif