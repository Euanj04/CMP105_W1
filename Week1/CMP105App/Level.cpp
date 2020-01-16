#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	sf::Vector2f half_size = static_cast<sf::Vector2f>(window->getSize());
	half_size.x /= 2;
	half_size.y /= 2;

	s_rect.setSize(sf::Vector2f(20, 20));
	s_rect.setOrigin(10, 10);
	s_rect.setPosition(100, 100);
	s_rect.setFillColor(sf::Color::Blue);

	m_rect.setSize(sf::Vector2f(40, 40));
	m_rect.setOrigin(20, 20);
	m_rect.setPosition(100, 100);
	m_rect.setFillColor(sf::Color::Green);

	l_rect.setSize(sf::Vector2f(60, 60));
	l_rect.setOrigin(30, 30);
	l_rect.setPosition(100, 100);
	l_rect.setFillColor(sf::Color::Red);

	bottom_right.setSize(sf::Vector2f(50, 50));
	bottom_right.setOrigin(50, 50);
	bottom_right.setFillColor(sf::Color::Green);

	circle.setRadius(50);
	circle.setOrigin(50, 50);
	circle.setPosition(half_size);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error loading arial\n";
	}

	text.setPosition(half_size.x, 10);
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	text.setString("Hello World.");
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2f pos = static_cast<sf::Vector2f>(window->getSize());
	bottom_right.setPosition(pos);
}

// Render level
void Level::render()
{
	beginDraw();
	drawObjects();
	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}

void Level::drawObjects()
{
	window->draw(circle);
	window->draw(l_rect);
	window->draw(m_rect);
	window->draw(s_rect);
	window->draw(text);
	window->draw(bottom_right);
}