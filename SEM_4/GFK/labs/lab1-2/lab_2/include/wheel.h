#pragma wheel

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <tuple>
#include <format>

namespace wheel
{
	class Wheels : public sf::Drawable
	{
	protected:
		sf::Font font;
		sf::Text* text;

		static const int R = 119;
		double defaultB = 128;
		double defaultY = 50;
		double defaultL = 0.5;
		double defaultV = 0.5;

		sf::Uint8* RGBPixels;
		sf::Texture* RGBTexture;
		sf::CircleShape* RGBCircle;

		sf::Uint8* CMYPixels;
		sf::Texture* CMYTexture;
		sf::CircleShape* CMYCircle;

		sf::Uint8* HSLPixels;
		sf::Texture* HSLTexture;
		sf::CircleShape* HSLCircle;

		sf::Uint8* HSVPixels;
		sf::Texture* HSVTexture;
		sf::CircleShape* HSVCircle;

	private:
		void calcWheels()
		{
			for (size_t x = 0; x < 2 * R; x++)
			{
				for (size_t y = 0; y < 2 * R; y++)
				{
					sf::Vector2f pos = sf::Vector2f(x, y) - sf::Vector2f(R, R); // position relative to center
					pos.y *= -1; // rotate measuring aparatus

					double r = sqrt(pos.x * pos.x + pos.y * pos.y);
					double a = round(atan2f(pos.y, pos.x) * 57.29577951f + 180);

					auto [rgb_r, rgb_g, rgb_b] = RGBToRGB({ a - 180, r , defaultB });
					auto [cmy_r, cmy_g, cmy_b] = RGBToCMY({ rgb_r, rgb_g, rgb_b });

					pos.x *= -1; // rotate measuring aparatus
					pos.y *= -1; // rotate measuring aparatus
					a = round(atan2f(pos.y, pos.x) * 57.29577951f + 180);

					auto [hsl_r, hsl_g, hsl_b] = HSLToRGB({ a, r * 0.008, defaultL });
					auto [hsv_r, hsv_g, hsv_b] = HSVToRGB({ a, r * 0.008, defaultV });

					if (r > R - 2)
					{
						rgb_r = 255;
						rgb_g = 255;
						rgb_b = 255;

						cmy_r = 255;
						cmy_g = 255;
						cmy_b = 255;
					}

					setPixelToRGBColor(RGBPixels, x, y, rgb_r, rgb_g, rgb_b);
					setPixelToRGBColor(CMYPixels, x, y, cmy_r, cmy_g, cmy_b);
					setPixelToRGBColor(HSLPixels, x, y, hsl_r, hsl_g, hsl_b);
					setPixelToRGBColor(HSVPixels, x, y, hsv_r, hsv_g, hsv_b);
				}
			}
		}

		static inline std::tuple<int, int, int> RGBToRGB(std::tuple<float, float, float> rgb)
		{
			auto [r, g, b] = std::tuple<int, int, int>();

			r = round(std::get<1>(rgb) / R * 256);
			g = round(std::get<0>(rgb) / 360 * 256);
			b = std::get<2>(rgb);

			return { r, g, b };
		};

		static inline std::tuple<int, int, int> RGBToCMY(std::tuple<float, float, float> rgb)
		{
			double C = 255 - std::get<0>(rgb);
			double M = 255 - std::get<1>(rgb);
			double Y = 255 - std::get<2>(rgb);

			return { C, M, Y };
		}

		static inline std::tuple<int, int, int> HSLToRGB(std::tuple<float, float, float> hsl)
		{
			auto [r, g, b] = std::tuple<int, int, int>();

			float C = (1.0f - fabsf(2.0f * std::get<2>(hsl) - 1.0f)) * std::get<1>(hsl);
			float X = C * (1.0f - fabsf(fmodf(std::get<0>(hsl) / 60.0f, 2.0f) - 1.0f));
			float m = std::get<2>(hsl) - C / 2.0f;
			if (std::get<0>(hsl) < 60)
			{
				r = (C + m) * 255;
				g = (X + m) * 255;
				b = (0 + m) * 255;
			} else if (std::get<0>(hsl) < 120)
			{
				r = (X + m) * 255;
				g = (C + m) * 255;
				b = (0 + m) * 255;
			} else if (std::get<0>(hsl) < 180)
			{
				r = (0 + m) * 255;
				g = (C + m) * 255;
				b = (X + m) * 255;
			} else if (std::get<0>(hsl) < 240)
			{
				r = (0 + m) * 255;
				g = (X + m) * 255;
				b = (C + m) * 255;
			} else if (std::get<0>(hsl) < 300)
			{
				r = (X + m) * 255;
				g = (0 + m) * 255;
				b = (C + m) * 255;
			} else
			{
				r = (C + m) * 255;
				g = (0 + m) * 255;
				b = (X + m) * 255;
			}

			return { r, g, b };
		};

		static inline std::tuple<int, int, int> HSVToRGB(std::tuple<float, float, float> hsv)
		{
			auto [r, g, b] = std::tuple<int, int, int>();

			float C = std::get<2>(hsv) * std::get<1>(hsv);
			float X = C * (1.0f - fabsf(fmodf(std::get<0>(hsv) * 0.016666f, 2.0f) - 1.0f));
			float m = std::get<2>(hsv) - C;
			if (std::get<0>(hsv) < 60)
			{
				r = (C + m) * 255;
				g = (X + m) * 255;
				b = (0 + m) * 255;
			} else if (std::get<0>(hsv) < 120)
			{
				r = (X + m) * 255;
				g = (C + m) * 255;
				b = (0 + m) * 255;
			} else if (std::get<0>(hsv) < 180)
			{
				r = (0 + m) * 255;
				g = (C + m) * 255;
				b = (X + m) * 255;
			} else if (std::get<0>(hsv) < 240)
			{
				r = (0 + m) * 255;
				g = (X + m) * 255;
				b = (C + m) * 255;
			} else if (std::get<0>(hsv) < 300)
			{
				r = (X + m) * 255;
				g = (0 + m) * 255;
				b = (C + m) * 255;
			} else
			{
				r = (C + m) * 255;
				g = (0 + m) * 255;
				b = (X + m) * 255;
			}

			return { r ,g, b };
		}

		inline void setPixelToRGBColor(sf::Uint8* target, int x, int y, double r, double g, double b)
		{
			target[4 * (y * 2 * R + x) + 0] = r;
			target[4 * (y * 2 * R + x) + 1] = g;
			target[4 * (y * 2 * R + x) + 2] = b;
			target[4 * (y * 2 * R + x) + 3] = 255;
		}

		void outtextxy(sf::RenderTarget& target, float x, float y, std::string str) const
		{
			text->setPosition(x, y);
			text->setString(str);
			target.draw(*text);
		}
	public:
		Wheels()
		{
			font.loadFromFile("TerminusTTF-4.40.1.ttf");

			text = new sf::Text;
			text->setFont(font);
			text->setCharacterSize(12);
			text->setFillColor(sf::Color::Black);

			RGBPixels = new sf::Uint8[4 * 4 * R * R]();
			CMYPixels = new sf::Uint8[4 * 4 * R * R]();
			HSLPixels = new sf::Uint8[4 * 4 * R * R]();
			HSVPixels = new sf::Uint8[4 * 4 * R * R]();


			RGBTexture = new sf::Texture();
			RGBTexture->create(2 * R, 2 * R);
			CMYTexture = new sf::Texture();
			CMYTexture->create(2 * R, 2 * R);
			HSLTexture = new sf::Texture();
			HSLTexture->create(2 * R, 2 * R);
			HSVTexture = new sf::Texture();
			HSVTexture->create(2 * R, 2 * R);

			RGBCircle = new sf::CircleShape(R);
			CMYCircle = new sf::CircleShape(R);
			HSLCircle = new sf::CircleShape(R);
			HSVCircle = new sf::CircleShape(R);

			calcWheels();

			RGBTexture->update(RGBPixels);
			RGBCircle->setTexture(RGBTexture);

			CMYTexture->update(CMYPixels);
			CMYCircle->setTexture(CMYTexture);

			HSLTexture->update(HSLPixels);
			HSLCircle->setTexture(HSLTexture);

			HSVTexture->update(HSVPixels);
			HSVCircle->setTexture(HSVTexture);
		};

		void setPosition(sf::Vector2f pos)
		{
			RGBCircle->setPosition(sf::Vector2f(pos.x + 300, pos.y + 300));
			CMYCircle->setPosition(sf::Vector2f(pos.x + 10, pos.y + 300));
			HSLCircle->setPosition(sf::Vector2f(pos.x + 10, pos.y + 10));
			HSVCircle->setPosition(sf::Vector2f(pos.x + 300, pos.y + 10));
		};

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			target.draw(*RGBCircle);
			target.draw(*CMYCircle);
			target.draw(*HSLCircle);
			target.draw(*HSVCircle);

			outtextxy(target, RGBCircle->getPosition().x + 10, RGBCircle->getPosition().y + 10, "RGB");
			outtextxy(target, CMYCircle->getPosition().x + 10, CMYCircle->getPosition().y + 10, "CMY");
			outtextxy(target, HSLCircle->getPosition().x + 10, HSLCircle->getPosition().y + 10, "HSL");
			outtextxy(target, HSVCircle->getPosition().x + 10, HSVCircle->getPosition().y + 10, "HSV");

			outtextxy(target, RGBCircle->getPosition().x + 2 * R - 25, RGBCircle->getPosition().y + 2 * R - 25, std::format("RGB = {:.0f}", defaultB));
			outtextxy(target, CMYCircle->getPosition().x + 2 * R - 25, CMYCircle->getPosition().y + 2 * R - 25, std::format("CMY = {:.2f}%", defaultY));
			outtextxy(target, HSLCircle->getPosition().x + 2 * R - 25, HSLCircle->getPosition().y + 2 * R - 25, std::format("HSL = {:.2f}", defaultL));
			outtextxy(target, HSVCircle->getPosition().x + 2 * R - 25, HSVCircle->getPosition().y + 2 * R - 25, std::format("HSV = {:.2f}", defaultV));
		}

		void handleBYLVValueChanged(double percent)
		{
			defaultB = 255 * percent;
			defaultY = percent;
			defaultL = percent;
			defaultV = percent;

			calcWheels();

			RGBTexture->update(RGBPixels);
			RGBCircle->setTexture(RGBTexture);

			CMYTexture->update(CMYPixels);
			CMYCircle->setTexture(CMYTexture);

			HSLTexture->update(HSLPixels);
			HSLCircle->setTexture(HSLTexture);

			HSVTexture->update(HSVPixels);
			HSVCircle->setTexture(HSVTexture);
		}

		virtual ~Wheels()
		{
			delete[] RGBPixels;
			delete RGBTexture;
			delete RGBCircle;

			delete[] CMYPixels;
			delete CMYTexture;
			delete CMYCircle;

			delete[] HSLPixels;
			delete HSLTexture;
			delete HSLCircle;

			delete[] HSVPixels;
			delete HSVTexture;
			delete HSVCircle;
		};
	};
}
