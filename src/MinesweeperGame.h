#pragma once
#include <string>;
#include "SFML/Graphics.hpp"

struct TextureData
{
	std::string tilesetPath = "./res/img/tileset.jpg";
	int tileSize = 32;
};

enum class GameplayState
{
	START,
	PLAY,
	PAUSE,
	DEFEAT,
	PLAY_TO_DEFEAT_TRANSITION
};


class MinesweeperGame
{
public:
	~MinesweeperGame();
	bool LoadTexture(TextureData inputData);

	void StartGame();


private:
	TextureData _textureData;
	GameplayState _gameplayState;

	int** _fieldData = nullptr;
	int** _fieldView = nullptr;

	sf::RenderWindow _window;
	sf::Texture tilesetTexture;


	void GenerateGameField();
	void DestroyGameField();

};