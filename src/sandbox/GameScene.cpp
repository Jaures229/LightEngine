#include "GameScene.h"

void GameScene::OnInitialize()
{
    std::vector<std::vector<char>> map = {
        {' ',' ',' ','#',' ',' ',' '},
        {' ',' ',' ','#',' ',' ',' '},
        {' ',' ',' ',' ','#',' ',' '},
        {' ',' ',' ',' ',' ','#',' '},
        {'#',' ',' ',' ',' ',' ',' '}
    };
    SetMap(map);
    _gameGrid.Init(_map);

    for (int row = 0; row < _gameGrid.GetGridSize().x; row++)
    {
        // draw line horizontal

        for (int col = 0; col < _gameGrid.GetGridSize().x; col++)
        {

            // draw line vertical
        }
    }
}

void GameScene::OnUpdate()
{
}

void GameScene::SetMap(std::vector<std::vector<char>> map)
{
    _map = map;
}
