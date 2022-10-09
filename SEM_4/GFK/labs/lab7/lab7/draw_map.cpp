#include <wx/wx.h>
#include "GUIMyFrame1.h"

// UWAGA: TO JEST JEDYNY PLIK, KTORY NALEZY EDYTOWAC **************************

#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <tuple>
#include <array>


#define PANEL_WIDTH 500
#define PANEL_HEIGHT 500


float Shepard(int N, float d[100][3], float x, float y)
{
	float l = 0, u = 0;

	for (size_t i = 0; i < N; i++)
	{
		float xk = d[i][0];
		float yk = d[i][1];
		float zk = d[i][2];

		float wk = 1. / ((x - xk) * (x - xk) + (y - yk) * (y - yk));
		//float wk = 1. / (pow(x - xk, 2) + pow(y - yk, 2));

		l += wk;
		u += wk * zk;
	}

	return u / l;
}

void GUIMyFrame1::DrawMap(int N, float d[100][3], bool Contour, int MappingType, int NoLevels, bool ShowPoints)
{
	wxMemoryDC memDC;
	memDC.SelectObject(MemoryBitmap);
	memDC.SetBackground(*wxWHITE_BRUSH);
	memDC.Clear();

	memDC.SetPen(*wxBLACK_PEN);
	memDC.SetBrush(*wxTRANSPARENT_BRUSH);

	auto approx_values = new float[PANEL_WIDTH][PANEL_HEIGHT]();

	for (int x = 0; x < PANEL_WIDTH; x++)
	{
		for (int y = 0; y < PANEL_HEIGHT; y++)
		{
			approx_values[x][y] = Shepard(N, d, x / 100.0 - 2.5, -y / 100.0 + 2.5); // x = [-2.5 2.5], y = [-2.5 2.5]
		}
	}

	float min = std::numeric_limits<float>::max(), max = std::numeric_limits<float>::min();
	for (size_t i = 0; i < N; i++)
	{
		float z = d[i][2];
		min = std::fminf(min, z);
		max = std::fmaxf(max, z);
	}

	if (MappingType == 1)
	{
		//memDC.DrawText("Mapa niebiesko-czerwona...", wxPoint(10, 30));

		unsigned char* data = new unsigned char[3 * PANEL_WIDTH * PANEL_HEIGHT];
		for (int x = 0; x < PANEL_WIDTH; x++) {
			for (int y = 0; y < PANEL_HEIGHT; y++) {
				float color = (approx_values[x][y] - min) / (max - min);
				data[y * PANEL_WIDTH * 3 + x * 3 + 0] = 255 * (1 - color);
				data[y * PANEL_WIDTH * 3 + x * 3 + 1] = 0;
				data[y * PANEL_WIDTH * 3 + x * 3 + 2] = 255 * color;
			}
		}

		memDC.DrawBitmap(wxBitmap(wxImage(PANEL_WIDTH, PANEL_HEIGHT, data)), 0, 0);
	}

	if (MappingType == 2)
	{
		//memDC.DrawText("Mapa niebiesko-zielono-czerwona...", wxPoint(10, 30));

		unsigned char* data = new unsigned char[3 * PANEL_WIDTH * PANEL_HEIGHT];
		for (int x = 0; x < PANEL_WIDTH; x++) {
			for (int y = 0; y < PANEL_HEIGHT; y++) {
				float color = (approx_values[x][y] - min) / (max - min);

				if (color < 0.5) {
					data[y * PANEL_WIDTH * 3 + x * 3 + 0] = 255 * (1 - 2 * color);
					data[y * PANEL_WIDTH * 3 + x * 3 + 1] = 2 * color * 255;
					data[y * PANEL_WIDTH * 3 + x * 3 + 2] = 0;
				}
				else {
					data[y * PANEL_WIDTH * 3 + x * 3 + 0] = 0;
					data[y * PANEL_WIDTH * 3 + x * 3 + 1] = 255 * (1 - 2 * color);
					data[y * PANEL_WIDTH * 3 + x * 3 + 2] = 0.5 * 255 * color;
				}
			}
		}

		memDC.DrawBitmap(wxBitmap(wxImage(PANEL_WIDTH, PANEL_HEIGHT, data)), 0, 0);

	}

	if (MappingType == 3)
	{
		//memDC.DrawText("Mapa szara...", wxPoint(10, 30));

		unsigned char* data = new unsigned char[3 * PANEL_WIDTH * PANEL_HEIGHT];
		for (int x = 0; x < PANEL_WIDTH; x++) {
			for (int y = 0; y < PANEL_HEIGHT; y++) {
				float color = (approx_values[x][y] - min) / (max - min);
				data[y * PANEL_WIDTH * 3 + x * 3 + 0] = 255 * color;
				data[y * PANEL_WIDTH * 3 + x * 3 + 1] = 255 * color;
				data[y * PANEL_WIDTH * 3 + x * 3 + 2] = 255 * color;
			}
		}

		memDC.DrawBitmap(wxBitmap(wxImage(PANEL_WIDTH, PANEL_HEIGHT, data)), 0, 0);
	}

	if (Contour)
	{
		int NoLevels = 5;

		std::vector<std::tuple<wxPoint, wxPoint>> contoursPoints;

		for (int i = 0; i < NoLevels; i++)
		{
			float treshhold = min + (i + 1) * (max - min) / (NoLevels + 1);

			for (int x = 1; x < PANEL_WIDTH - 1; x++)
			{
				for (int y = 1; y < PANEL_HEIGHT - 1; y++)
				{
					unsigned char code =
						(approx_values[x - 1][y - 1] > treshhold ? 1 : 0) |
						(approx_values[x - 1][y + 1] > treshhold ? 2 : 0) |
						(approx_values[x + 1][y - 1] > treshhold ? 4 : 0) |
						(approx_values[x + 1][y + 1] > treshhold ? 8 : 0);

					switch (code)
					{
						// 1 + 14 = 15 
					case 1:
					case 14:
						contoursPoints.push_back({ wxPoint(x - 1, y + 0), wxPoint(x + 0, y - 1) });
						break;

						// 2 + 13 = 15 
					case 2:
					case 13:
						contoursPoints.push_back({ wxPoint(x - 1, y + 0), wxPoint(x + 0, y + 1) });
						break;

						// 2 + 12 = 15 
					case 3:
					case 12:
						contoursPoints.push_back({ wxPoint(x + 0, y - 1), wxPoint(x + 0, y + 1) });
						break;

						// 4 + 11 = 15
					case 4:
					case 11:
						contoursPoints.push_back({ wxPoint(x + 1, y + 0), wxPoint(x + 0, y + 1) });
						break;

					case 5:
						contoursPoints.push_back({ wxPoint(x + 0, y - 1), wxPoint(x + 1, y + 0) });
						contoursPoints.push_back({ wxPoint(x - 1, y + 0), wxPoint(x + 0, y + 1) });
						break;

					case 10:
						contoursPoints.push_back({ wxPoint(x - 1, y + 0), wxPoint(x + 0, y - 1) });
						contoursPoints.push_back({ wxPoint(x + 0, y + 1), wxPoint(x + 1, y + 0) });
						break;

						// 6 + 9 == 15
					case 6:
					case 9:
						contoursPoints.push_back({ wxPoint(x - 1, y + 0), wxPoint(x + 1, y + 0) });
						break;

						// 7 + 8 == 15
					case 7:
					case 8:
						contoursPoints.push_back({ wxPoint(x + 0, y - 1), wxPoint(x + 1, y + 0) });
						break;
					}
				}
			}

			for (auto& item : contoursPoints) memDC.DrawLine(std::get<0>(item), std::get<1>(item));
		}
	}

	if (ShowPoints)
	{
		//memDC.DrawText("Punkty...", wxPoint(10, 50));
		for (size_t i = 0; i < N; i++)
		{
			int x = (d[i][0] + 2.5) * 100;
			int y = (-d[i][1] + 2.5) * 100;

			memDC.DrawLine(x - 5, y, x + 5, y);
			memDC.DrawLine(x, y - 5, x, y + 5);
		}
	}

	auto bitmap = memDC.GetAsBitmap();
	auto image = bitmap.ConvertToImage();
	double alpha = NoLevels * M_PI / 180.0f;
	image = image.Rotate(alpha, wxPoint(0, 0));

	memDC.Clear();

	memDC.DrawBitmap(wxBitmap(image), 0, 0);

	delete[] approx_values;
}
