#pragma once
#include "Scene.h"
#include "Grid.h"
#include <vector>
#include "TileEntity.h"

class GameScene : public Scene
{
public:
    void OnInitialize() override;
    void OnUpdate() override;
    void SetMap(std::vector<std::vector<char>> map);
private:
    Grid _gameGrid;
    std::vector<std::vector<TileEntity*>> _tilesEnttities;
    std::vector<std::vector<char>> _map;
    Vector2f _playerPos = { 0.0f, 0.0f };
    Vector2f _cursorPos = { 0.0f, 0.0f };


    // init les tiles entities à partir de l'interface
    // 
};
