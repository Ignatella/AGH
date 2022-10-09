#pragma once 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace app
{
	class App
	{
	private:
		sf::Font font;
		sf::Text* text;

	public:
		App()
		{
			font.loadFromFile("TerminusTTF-4.40.1.ttf");

			text = new sf::Text;
			text->setFont(font);
			text->setCharacterSize(12);
			text->setFillColor(sf::Color::Black);
		}

		void outtextxy(sf::RenderTarget& target, float x, float y, std::string str)
		{
			text->setPosition(x, y);
			text->setString(str);
			target.draw(*text);
		};
	};
}