#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>

#include <appMode.h>

namespace App
{
	class App : public sf::Drawable
	{
	private:
		AppMode current_mode;

		sf::Font font;
		sf::Color draw_color;
		sf::Color fill_color;
		sf::Text* text;
		sf::RectangleShape* rectangle;

		sf::Texture* colors_texture;
		sf::Sprite* colors_sprite;
		sf::Uint8* colors_pixels;
		sf::RectangleShape* draw_color_rect;
		sf::RectangleShape* fill_color_rect;

		sf::RenderTexture* drawing_texture;
		sf::Sprite* drawing_sprite;

		bool isDrawing;

		std::vector<sf::Drawable*> shapes;

		const unsigned int window_size_x = 800;
		const unsigned int window_size_y = 650;
		const unsigned int colors_size_x = 765;
		const unsigned int colors_size_y = 60;
		const unsigned int colors_selection_size_x = 28;
		const unsigned int colors_selection_size_y = 25;
		const unsigned int bottom_menu_x = window_size_x;
		const unsigned int bottom_menu_y = 50;

		const std::string img_file = "sfml-result.png";

		inline void draw_to_color_pixels(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b)
		{
			colors_pixels[4 * (y * colors_size_x + x) + 0] = r;
			colors_pixels[4 * (y * colors_size_x + x) + 1] = g;
			colors_pixels[4 * (y * colors_size_x + x) + 2] = b;
			colors_pixels[4 * (y * colors_size_x + x) + 3] = 255;
		}
		inline std::tuple<int, int, int> get_menu_color(int x, int y)
		{
			int r = colors_pixels[4 * (y * colors_size_x + x) + 0];
			int g = colors_pixels[4 * (y * colors_size_x + x) + 1];
			int b = colors_pixels[4 * (y * colors_size_x + x) + 2];

			return { r, g, b };
		}

	private:
#pragma region Draw
		inline void draw_current_color_rectanges(sf::RenderTarget& target) const
		{
			draw_color_rect->setFillColor(draw_color);
			fill_color_rect->setFillColor(fill_color);

			target.draw(*draw_color_rect);
			target.draw(*fill_color_rect);
		}
		void outtextxy(sf::RenderTarget& target, float x, float y, std::string str) const
		{
			text->setPosition(x, y);
			text->setString(str);
			target.draw(*text);
		}
		void draw_shapes(sf::RenderTarget& target) const
		{
			for (sf::Drawable* shape : shapes)
				target.draw(*shape);
		}
		void draw_black_bounds(sf::RenderTarget& target) const
		{
			sf::RectangleShape top_rec(sf::Vector2f(window_size_x, colors_size_y));
			sf::RectangleShape bottom_rec(sf::Vector2f(window_size_x, bottom_menu_y));
			top_rec.setFillColor(sf::Color());
			bottom_rec.setFillColor(sf::Color());
			bottom_rec.setPosition(0, window_size_y - bottom_menu_y);
			target.draw(top_rec);
			target.draw(bottom_rec);
		}
#pragma endregion

	public:
#pragma region Ctors
		App()
		{
			current_mode = AppMode::Default;
			isDrawing = false;

			font.loadFromFile("TerminusTTF-4.40.1.ttf");
			draw_color = sf::Color::Transparent;
			fill_color = sf::Color::Transparent;
			text = new sf::Text;
			text->setFont(font);
			text->setCharacterSize(12);
			text->setFillColor(sf::Color::White);

			rectangle = new sf::RectangleShape(sf::Vector2f(window_size_x - 2, window_size_y - colors_size_y - bottom_menu_y));
			rectangle->setFillColor(sf::Color::Transparent);
			rectangle->setOutlineColor(sf::Color::White);
			rectangle->setOutlineThickness(1.0f);
			rectangle->setPosition(1, colors_size_y + 1);

			unsigned int x, y;
			colors_pixels = new sf::Uint8[colors_size_x * colors_size_y * 4];
			for (x = 0; x < 255; x++)
				for (y = 0; y < 30; y++)
				{
					draw_to_color_pixels(x, y, x, 255, 0);
					draw_to_color_pixels(x + 255, y, 255, 255 - x, 0);
					draw_to_color_pixels(x + 510, y, 255, 0, x);
					draw_to_color_pixels(254 - x, y + 30, 0, 255, 255 - x);
					draw_to_color_pixels(509 - x, y + 30, 0, x, 255);
					draw_to_color_pixels(764 - x, y + 30, 255 - x, 0, 255);
				}

			colors_texture = new sf::Texture();
			colors_texture->create(colors_size_x, colors_size_y);
			colors_texture->update(colors_pixels);

			colors_sprite = new sf::Sprite();
			colors_sprite->setTexture(*colors_texture);
			colors_sprite->setPosition(0, 0);

			draw_color_rect = new sf::RectangleShape(sf::Vector2f(colors_selection_size_x, colors_selection_size_y));
			draw_color_rect->setPosition(sf::Vector2f(colors_size_x + 3, 0 + 3));
			fill_color_rect = new sf::RectangleShape(sf::Vector2f(colors_selection_size_x, colors_selection_size_y));
			fill_color_rect->setPosition(sf::Vector2f(colors_size_x + 3, colors_selection_size_y + 2 * 3));

			shapes = std::vector<sf::Drawable*>();

			drawing_texture = new sf::RenderTexture();
			drawing_texture->create(window_size_x, window_size_y - colors_size_y - bottom_menu_y);

			drawing_sprite = new sf::Sprite();
			drawing_sprite->setPosition(sf::Vector2f(0, colors_size_y));
		}
#pragma endregion

#pragma region ModeChangeHandler

		void handleModeChange(sf::Keyboard::Key code)
		{
			switch (code)
			{
			case sf::Keyboard::F:
				current_mode = AppMode::SelectingDrawColor;
				break;
			case sf::Keyboard::B:
				current_mode = AppMode::SelectingFillColor;
				break;
			case sf::Keyboard::L:
				current_mode = AppMode::DrawingLine;
				break;
			case sf::Keyboard::R:
				current_mode = AppMode::DrawingRectangle;
				break;
			case sf::Keyboard::A:
				current_mode = AppMode::DrawingFilledRectangle;
				break;
			case sf::Keyboard::C:
				current_mode = AppMode::DrawingCircle;
				break;
			case sf::Keyboard::W:
				saveToFile();
				current_mode = AppMode::Default;
				break;
			case sf::Keyboard::O:
				readFromFile();
				current_mode = AppMode::Default;
				break;
			}
		}
#pragma endregion

#pragma region Drawable
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			drawing_texture->clear(sf::Color::Black);
			draw_shapes(*drawing_texture);
			drawing_texture->display();

			drawing_sprite->setTexture(drawing_texture->getTexture());
			target.draw(*drawing_sprite);

			draw_black_bounds(target);

			outtextxy(target, 5, 600, "f - wybor koloru rysowania");
			outtextxy(target, 5, 615, "b - wybor koloru wypelniania");
			outtextxy(target, 5, 630, "l - rysowanie linii");

			outtextxy(target, 200, 600, "r - rysowanie prostokata");
			outtextxy(target, 200, 615, "a - rysowanie wypelnionego prostokata");
			outtextxy(target, 200, 630, "c - rysowanie okregu");

			outtextxy(target, 470, 600, "w - zapis do pliku");
			outtextxy(target, 470, 615, "o - odczyt z pliku");
			outtextxy(target, 470, 630, "esc - wyjscie");

			outtextxy(target, 650, 615, std::string("Aktualne: ") + std::string(1, current_mode));

			target.draw(*rectangle);
			target.draw(*colors_sprite);

			draw_current_color_rectanges(target);
		}
#pragma endregion

#pragma region ColorPicker

		bool isColorPickerClickAllowed(unsigned int x, unsigned int y)
		{
			if (x < colors_size_x && y < colors_size_y)
			{
				return true;
			}

			return false;
		}

		void handleColorPickerClick(unsigned int x, unsigned int y)
		{
			auto [r, g, b] = get_menu_color(x, y);

			if (current_mode == AppMode::SelectingDrawColor)
			{
				draw_color = sf::Color(r, g, b);
			}

			if (current_mode == AppMode::SelectingFillColor)
			{
				fill_color = sf::Color(r, g, b);
			}
		}

#pragma endregion

#pragma region DrawingHandlers
		bool isDrawingAllowed(sf::Vector2i pos)
		{
			if (pos.y > colors_size_y + 1 && pos.y < window_size_y - bottom_menu_y - 1)
			{
				return true;
			}

			return false;
		}

		void handleMouseMove(sf::Vector2i pos)
		{
			sf::Vector2f pos2f = sf::Vector2f(pos);
			pos2f.y -= colors_size_y;

			if (current_mode == AppMode::DrawingLine)
				handleDrawLine(pos2f);
			if (current_mode == AppMode::DrawingCircle)
				handleDrawCircle(pos2f);
			if (current_mode == AppMode::DrawingRectangle || current_mode == AppMode::DrawingFilledRectangle)
				handleDrawRectangle(pos2f);
		}

		void handleDrawCircle(sf::Vector2f pos)
		{
			if (isDrawing == false)
			{
				sf::CircleShape* circle = new sf::CircleShape();
				circle->setPosition(pos);
				circle->setOutlineThickness(3);
				circle->setOutlineColor(draw_color);
				circle->setFillColor(fill_color);

				shapes.push_back(circle);
				isDrawing = true;

				return;
			}

			sf::Drawable* shape = shapes.back();
			sf::CircleShape* circle = static_cast<sf::CircleShape*>(shape);

			float radius = circle->getRadius();
			sf::Vector2f p = circle->getPosition();
			sf::Vector2f center = p + sf::Vector2f(radius, radius);

			sf::Vector2f delta = pos - center;

			float len = sqrtf(delta.x * delta.x + delta.y * delta.y) - radius;
			circle->setPosition(p.x - len, p.y - len);
			circle->setRadius(radius + len);
		}

		void handleDrawRectangle(sf::Vector2f pos)
		{
			sf::Color fillColor = sf::Color::Transparent;

			if (current_mode == AppMode::DrawingFilledRectangle) fillColor = fill_color;

			if (isDrawing == false)
			{
				sf::RectangleShape* rect = new sf::RectangleShape();
				rect->setPosition(pos);
				rect->setOutlineThickness(3);
				rect->setOutlineColor(draw_color);
				rect->setFillColor(fillColor);

				shapes.push_back(rect);
				isDrawing = true;

				return;
			}

			sf::Drawable* shape = shapes.back();
			sf::RectangleShape* rect = static_cast<sf::RectangleShape*>(shape);

			sf::Vector2f rectCorner = rect->getPosition();
			rect->setSize(sf::Vector2f(pos.x - rectCorner.x, pos.y - rectCorner.y));
		}

		void handleDrawLine(sf::Vector2f pos)
		{
			if (isDrawing == false)
			{
				sf::VertexArray* line = new sf::VertexArray(sf::LinesStrip, 2);
				(*line)[0].position = pos;
				(*line)[0].color = draw_color;
				(*line)[1].position = pos;
				(*line)[1].color = fill_color;

				shapes.push_back(line);
				isDrawing = true;

				return;
			}

			sf::Drawable* shape = shapes.back();
			sf::VertexArray* line = static_cast<sf::VertexArray*>(shape);
			(*line)[1].position = pos;
		}

		void endDrawing()
		{
			isDrawing = false;
		}
#pragma endregion

#pragma region FileHalpers
		void saveToFile()
		{
			drawing_sprite->getTexture()->copyToImage().saveToFile(img_file);
		}

		void readFromFile()
		{
			sf::Image img;

			if (!img.loadFromFile(img_file)) return;

			sf::Texture* tx = new sf::Texture();
			tx->loadFromImage(img);

			sf::Sprite* sp = new sf::Sprite(*tx);

			shapes.push_back(sp);
		}

#pragma endregion
	};
}
