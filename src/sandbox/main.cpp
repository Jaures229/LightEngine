#include <iostream>
#include "main.h"
#include "GameManager.h"
#include "GameScene.h"

int main()
{
    GameManager* game = GameManager::Get();

    game->LaunchScene<GameScene>(1280, 720, "GameScene", Color{ 25, 25, 35 });
    return 0;
}
