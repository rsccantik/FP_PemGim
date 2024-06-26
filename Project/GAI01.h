#ifndef GAI01_H
#define GAI01_H

#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include <vector>
#include "GameObject.h"

namespace Engine {
    class GAI01 :public Engine::Game
    {
    public:
        GAI01(Setting* setting);
        ~GAI01();
        virtual void Init();
        virtual void Update();
        virtual void Render();

        bool isActive;
    private:
        Texture* texture, * texture2;
        Sprite* playerSprite, * botSprite, * projectiles;
        vec2 botVelocity, playerDirection;
        float x1, y1, maxX, minX, maxY, minY;

        string FacingBotSprite(vec2 position, vec2 target);
        void ControlPlayerSprite();
        void CreatePlayerSprite();
        void ControBotSprite();
        void CreateBotSprite();
        void CreateProjectiles();
        void ShootProjectile();
        vec2 Seek(vec2 position, vec2 velocity, vec2 target, float maxSpeed);
        vec2 Flee(vec2 position, vec2 velocity, vec2 target, float maxSpeed);
        vec2 Arrival(vec2 position, vec2 target, vec2 botVelocity, float maxSpeed, float slowRadius);

        vector<Engine::GameObject*> objects;
        float spawnDuration = 0, maxSpawnTime = 0, numObjectsInPool = 0, numObjectPerSpawn = 0;

    };
}
#endif