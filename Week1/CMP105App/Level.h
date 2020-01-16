#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	void beginDraw();
	void endDraw();
	void drawObjects();
	sf::RenderWindow* window;

	sf::RectangleShape s_rect;
	sf::RectangleShape m_rect;
	sf::RectangleShape l_rect;

	sf::RectangleShape bottom_right;

	sf::CircleShape circle;

	sf::Font font;
	sf::Text text;
};