#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include <app.h>
#include <appMode.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 01", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;
	App::App app;

	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		window.clear(sf::Color::Black);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

			sf::Vector2i pos = sf::Mouse::getPosition(window);

			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (event.type == sf::Event::MouseButtonReleased)
				{
					bool canHandle = app.isColorPickerClickAllowed(pos.x, pos.y);
					if (canHandle) app.handleColorPickerClick(pos.x, pos.y);
					app.endDrawing();
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				bool canHandle = app.isDrawingAllowed(pos);
				if (canHandle) app.handleMouseMove(pos);
			}

			if (event.type == sf::Event::KeyPressed)
			{
				app.handleModeChange(event.key.code);
			}
		}

		window.draw(app);
		window.display();
	}
	return 0;
}
