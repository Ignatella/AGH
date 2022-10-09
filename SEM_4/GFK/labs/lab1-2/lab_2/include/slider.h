#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>

namespace slider
{
	class Slider : public sf::Drawable
	{
		const double sliderX = 675;
		const double sliderY = 25;

		const double sliderHeight = 275;
		const double sliderWidth = 25;

		const double sliderLineLen = 10;

		bool isSliding;

		sf::RectangleShape* sliderBounds;
		sf::Vertex* sliderGradient;

		double currLinesPosition = 0.5;

		sf::VertexArray* lineLeft;
		sf::VertexArray* lineRight;

	public:
		Slider()
		{
			isSliding = false;

			sliderGradient = new sf::Vertex[4]();
			sliderGradient[0] = sf::Vertex(sf::Vector2f(sliderX, sliderY), sf::Color::Black);
			sliderGradient[1] = sf::Vertex(sf::Vector2f(sliderX + sliderWidth, sliderY), sf::Color::Black);
			sliderGradient[2] = sf::Vertex(sf::Vector2f(sliderX + sliderWidth, sliderY + sliderHeight), sf::Color::White);
			sliderGradient[3] = sf::Vertex(sf::Vector2f(sliderX, sliderY + sliderHeight), sf::Color::White);

			sliderBounds = new sf::RectangleShape(sf::Vector2f(sliderWidth, sliderHeight));
			sliderBounds->setPosition(sf::Vector2f(sliderX, sliderY));
			sliderBounds->setFillColor(sf::Color::Transparent);
			sliderBounds->setOutlineColor(sf::Color::Black);
			sliderBounds->setOutlineThickness(3);

			lineLeft = new sf::VertexArray(sf::LinesStrip, 2);
			(*lineLeft)[0].color = sf::Color::Black;
			(*lineLeft)[1].color = sf::Color::Black;

			lineRight = new sf::VertexArray(sf::LinesStrip, 2);
			(*lineRight)[0].color = sf::Color::Black;
			(*lineRight)[1].color = sf::Color::Black;
		};

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			(*lineLeft)[0].position = sf::Vector2f(sliderX - 2 * sliderLineLen, sliderY + sliderHeight * currLinesPosition);
			(*lineLeft)[1].position = sf::Vector2f(sliderX - 2 * sliderLineLen + sliderLineLen, sliderY + sliderHeight * currLinesPosition);
			(*lineRight)[0].position = sf::Vector2f(sliderX + sliderWidth + 1 * sliderLineLen - 3, sliderY + sliderHeight * currLinesPosition);
			(*lineRight)[1].position = sf::Vector2f(sliderX + sliderWidth + 1 * sliderLineLen + sliderLineLen - 3, sliderY + sliderHeight * currLinesPosition);

			target.draw(sliderGradient, 4, sf::Quads);
			target.draw(*sliderBounds);
			target.draw(*lineLeft);
			target.draw(*lineRight);
		};

		double handleLeftButtonPressed(sf::Vector2i pos)
		{
			if (pos.x <= sliderX || pos.x >= sliderX + sliderWidth) return -1;
			if (pos.y <= sliderY || pos.y >= sliderY + sliderHeight) return -1;

			if (isSliding == false) isSliding = true;

			currLinesPosition = (pos.y - sliderY) / sliderHeight;

			if (currLinesPosition > 1) currLinesPosition = 0.999;
			if (currLinesPosition <= 0) currLinesPosition = 0.001;

			return currLinesPosition;
		};

		double handleLeftButtonReleased(sf::Vector2i pos)
		{
			if (isSliding == false) return -1;

			isSliding = false;

			double newPos = (pos.y - sliderY) / sliderHeight;

			currLinesPosition = newPos;

			if (currLinesPosition > 1) currLinesPosition = 0.9999;
			if (currLinesPosition <= 0) currLinesPosition = 0.0001;

			return currLinesPosition;
		};

		~Slider()
		{
			delete sliderBounds;
			delete[] sliderGradient;
			delete lineLeft;
			delete lineRight;
		};
	};
}