#include "MinesweeperGame.h"

//////////////////////////////////////////////////////////////////////////////

MinesweeperGame::~MinesweeperGame()
{
	DestroyGameField();
}

//////////////////////////////////////////////////////////////////////////////

bool MinesweeperGame::LoadTexture(TextureData inputData)
{
	_textureData = inputData;
	if (!tilesetTexture.loadFromFile(_textureData.tilesetPath))
	{
		return false;
	}

	return true;
}

//////////////////////////////////////////////////////////////////////////////

void MinesweeperGame::StartGame()
{
	_window.create(sf::VideoMode(400, 400), "Minesweeper!");

	sf::Sprite sprite(tilesetTexture);

	GenerateGameField();

	while (_window.isOpen())
	{
		sf::Event inputEvent;

		///////////////////////////////////////////////////////////////
		//Handle inputs
		///////////////////////////////////////////////////////////////
		while (_window.pollEvent(inputEvent))
		{
			if (inputEvent.type == sf::Event::Closed)
			{
				_window.close();
			}

			switch (_gameplayState)
			{
				case GameplayState::PLAY:
				{
					if (inputEvent.type == sf::Event::MouseButtonReleased)
					{
						if (inputEvent.key.code == sf::Mouse::Left) ;
						else if (inputEvent.key.code == sf::Mouse::Right) ;
						
					}

					break;
				}
				case GameplayState::DEFEAT:
				{
					if (inputEvent.type == sf::Event::KeyPressed)
					{
						if (inputEvent.key.code == sf::Keyboard::R)
						{
							
							break;
						}

						if (inputEvent.key.code == sf::Keyboard::Q)
						{
							_window.close();
							break;
						}

					}

					break;
				}
			}
		}

		///////////////////////////////////////////////////////////////
		//Handle logic update
		///////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////
		//Handle draw update
		///////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////
		//Handle draw
		///////////////////////////////////////////////////////////////

		_window.clear(sf::Color::White);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
			{
				sprite.setTextureRect(sf::IntRect(_fieldView[i][j] * _textureData.tileSize, 0, _textureData.tileSize, _textureData.tileSize));
				sprite.setPosition(i * _textureData.tileSize, j * _textureData.tileSize);
				_window.draw(sprite);
			}

		_window.display();
	}

}

//////////////////////////////////////////////////////////////////////////////

void MinesweeperGame::GenerateGameField()
{
	_fieldData = new int* [10];
	_fieldView = new int* [10];

	for (int i = 0; i < 10; i++)
	{
		_fieldData[i] = new int[10];
		_fieldView[i] = new int[10];

		for (int j = 0; j < 10; j++)
		{
			if (rand() % 5 == 0) _fieldData[i][j] = 9;
			else _fieldData[i][j] = 0;

			_fieldView[i][j] = 10;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////

void MinesweeperGame::DestroyGameField()
{
	for (int i = 0; i < 10; i++)
	{
		delete[] _fieldData[i];
		delete[] _fieldView[i];
	}
	
	delete[] _fieldData;
	delete[] _fieldView;
}

//////////////////////////////////////////////////////////////////////////////

