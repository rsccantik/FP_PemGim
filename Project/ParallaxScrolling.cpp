#include "ParallaxScrolling.h"

Engine::ParallaxScrolling::ParallaxScrolling(Setting* setting) :Engine::Game(setting)
{
	setting->windowTitle = "Parallax Scrolling";
}

Engine::ParallaxScrolling::~ParallaxScrolling()
{
}

void Engine::ParallaxScrolling::Init()
{
	for (int i = 0; i <= 0; i++) {
		AddToLayer(backgrounds, "bg_0" + to_string(i) + ".png");
	}
	for (int i = 1; i <= 1; i++) {
		AddToLayer(middlegrounds, "bg_1" + to_string(i) + ".png");
	}
	for (int i = 2; i <= 2; i++) {
		AddToLayer(foregrounds, "bg_2" + to_string(i) + ".png");
	}

	offset = 2;
}

void Engine::ParallaxScrolling::Update()
{
	MoveLayer(backgrounds, 0.005f);
	MoveLayer(middlegrounds, 0.03f);
	MoveLayer(foregrounds, 0.5f);
}

void Engine::ParallaxScrolling::Render()
{
	DrawLayer(backgrounds);
	DrawLayer(middlegrounds);
	DrawLayer(foregrounds);
}

void Engine::ParallaxScrolling::MoveLayer(vector<Sprite*>& bg, float speed)
{
	for (Sprite* s : bg) {
		if (s->GetPosition().x < -setting->screenWidth + offset) {
			s->SetPosition(setting->screenWidth + offset - 1, 0);
		}
		s->SetPosition(s->GetPosition().x - speed * GetGameTime(), s->GetPosition().y);
		s->Update(GetGameTime());
	}
}

void Engine::ParallaxScrolling::DrawLayer(vector<Sprite*>& bg)
{
	for (Sprite* s : bg) {
		s->Draw();
	}
}

void Engine::ParallaxScrolling::AddToLayer(vector<Sprite*>& bg, string name)
{
	Texture* texture = new Texture(name);

	Sprite* s = new Sprite(texture, defaultSpriteShader, defaultQuad);
	s->SetSize(setting->screenWidth + offset, setting->screenHeight);
	bg.push_back(s);

	Sprite* s2 = new Sprite(texture, defaultSpriteShader, defaultQuad);
	s2->SetSize(setting->screenWidth + offset, setting->screenHeight)->SetPosition(setting->screenWidth + offset - 1, 0);
	bg.push_back(s2);
}

