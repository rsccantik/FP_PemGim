#include "Setting.h"
#include "Game.h"

#include "Demo.h"
#include "NPCWave.h"
#include "ParallaxScrolling.h"
#include "GUI.h"

int main(int argc, char** argv) {
	Engine::Setting* setting = new Engine::Setting();
	setting->screenWidth = 1600;
	setting->screenHeight = 900;
	setting->windowFlag = Engine::WindowFlag::FULLSCREEN;
	setting->vsync = false;
	setting->targetFrameRate = 75;
	Engine::Game* game = new Engine::NPCWave(setting);
	game->Run();
	delete setting;	
	delete game;

	return 0;
}
