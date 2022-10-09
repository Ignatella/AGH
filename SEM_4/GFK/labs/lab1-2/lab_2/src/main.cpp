#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <format>

#include "wheel.h"
#include "slider.h"
#include "app.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GFK Lab 02", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;

	app::App app;
	wheel::Wheels w;
	slider::Slider s;

	w.setPosition(sf::Vector2f(25, 25));

	sf::Clock clock;
	sf::Time time = sf::Time::Zero;
	unsigned int FPS = 0, frame_counter = 0;

	clock.restart().asMilliseconds();

	while (window.isOpen())
	{
		sf::Event event;
		window.clear(sf::Color::White);

		while (window.pollEvent(event))
		{
			sf::Vector2i pos = sf::Mouse::getPosition(window);

			if (event.type == sf::Event::Closed) window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();


			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (event.type == sf::Event::MouseButtonReleased)
				{
					double res = s.handleLeftButtonReleased(pos);
					if (res > 0) w.handleBYLVValueChanged(res);
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				double res = s.handleLeftButtonPressed(pos);
				// if (res > 0) w.handleBYLVValueChanged(res);
			}
		}

		if (clock.getElapsedTime().asSeconds() >= 1.0f)
		{
			FPS = (unsigned int)((float)frame_counter / clock.getElapsedTime().asSeconds());
			clock.restart();
			frame_counter = 0;
		}
		frame_counter++;

		app.outtextxy(window, 635, 320, "Frames per second:");
		app.outtextxy(window, 675, 340, std::format("{0}", FPS));

		window.draw(w);
		window.draw(s);
		window.display();
	}
	return 0;
}
