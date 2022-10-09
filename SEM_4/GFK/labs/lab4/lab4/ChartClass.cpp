#include <wx/dc.h>
#include <memory>

#include "ChartClass.h"
#include "vecmat.h"

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c)
{
	cfg = std::move(c);
	x_step = 1000;
}

void ChartClass::Set_Range()
{
	double xmin = 9999.9, xmax = -9999.9, ymin = 9999.9, ymax = -9999.9;
	double x, y, step;
	int i;

	xmin = cfg->Get_x_start();
	xmax = cfg->Get_x_stop();

	step = (cfg->Get_x_stop() - cfg->Get_x_start()) / x_step;
	x = cfg->Get_x_start();

	for (i = 0; i <= x_step; i++)
	{
		y = GetFunctionValue(x);
		if (y > ymax) ymax = y;
		if (y < ymin) ymin = y;
		x = x + step;
	}

	y_min = ymin;
	y_max = ymax;
	x_min = xmin;
	x_max = xmax;
}

double ChartClass::GetFunctionValue(double x)
{
	if (cfg->Get_F_type() == 1) return x * x;
	if (cfg->Get_F_type() == 2) return 0.5 * exp(4 * x - 3 * x * x);
	return x + sin(x * 4.0);
}

void ChartClass::Draw(wxDC* dc, int w, int h)
{
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(RGB(255, 0, 0)));
	dc->DrawRectangle(10, 10, w - 20, h - 20);
	dc->SetClippingRegion(wxRect(10, 10, w - 20, h - 20));
	Set_Range();

	const double x0 = cfg->Get_x0(), x1 = cfg->Get_x1(), y0 = cfg->Get_y0(), y1 = cfg->Get_y1();
	const double x_start = cfg->Get_x_start(), x_stop = cfg->Get_x_stop();
	const double delta_x = cfg->Get_dX(), delta_y = cfg->Get_dY();
	const double dx = (x_max - x_min) / x_step;
	const double alpha = cfg->Get_Alpha();

	Matrix t;

	if (cfg->RotateScreenCenter())
	{
		double disX = (x1 + x0) / 2, disY = (y1 + y0) / 2;

		t =
			GetTranslationMatrix(w / 2, h / 2) *
			GetRotationMatrix(-alpha) *
			GetTranslationMatrix(-disX / (x1 - x0) * w, disY / (y1 - y0) * h) *
			GetTranslationMatrix(delta_x / (x1 - x0) * w, delta_y / (y1 - y0) * h) *
			GetScaleMatrix(w - 20, h - 20, x0, x1, y0, y1);
	} else
	{
		double disX = (x1 + x0) / 2, disY = (y1 + y0) / 2;

		t =
			GetTranslationMatrix(-disX / (x1 - x0) * w, disY / (y1 - y0) * h) *
			GetTranslationMatrix(delta_x / (x1 - x0) * w, delta_y / (y1 - y0) * h) *
			GetTranslationMatrix(w / 2, h / 2) *
			GetRotationMatrix(-alpha) *
			GetScaleMatrix(w - 20, h - 20, x0, x1, y0, y1);
	}

	dc->SetPen(wxPen(RGB(160, 131, 240)));

	if (x0 <= 0 && x1 >= 0)

	{
		DrawLine2d(dc, t, 0, y_min, 0, y_max);

		DrawLine2d(dc, t, 0, y_max, 0.025, y_max - 0.1);
		DrawLine2d(dc, t, 0, y_max, -0.025, y_max - 0.1);


		DrawTxt(dc, t, alpha, 0.1, y_max, y_max);
		DrawTxt(dc, t, alpha, 0.1, y_max / 2, y_max / 2);
		DrawTxt(dc, t, alpha, 0.1, y_min, y_min);
		DrawTxt(dc, t, alpha, 0.1, y_min / 2, y_min / 2);
		DrawLine2d(dc, t, -0.05, y_max, 0.05, y_max);
		DrawLine2d(dc, t, -0.05, y_max / 2, 0.05, y_max / 2);
		DrawLine2d(dc, t, -0.05, y_min, 0.05, y_min);
		DrawLine2d(dc, t, -0.05, y_min / 2, 0.05, y_min / 2);
	}

	if (y0 <= 0 && y1 >= 0)
	{
		DrawLine2d(dc, t, x_start, 0, x_stop, 0);

		DrawLine2d(dc, t, x_stop, 0, x_stop - 0.05, 0.05);
		DrawLine2d(dc, t, x_stop, 0, x_stop - 0.05, -0.05);

		DrawTxt(dc, t, alpha, x_stop, 0, x_stop);
		DrawTxt(dc, t, alpha, x_stop / 2, 0, x_stop / 2);
		DrawTxt(dc, t, alpha, x_start, 0, x_start);
		DrawTxt(dc, t, alpha, x_start / 2, 0, x_start / 2);
		DrawLine2d(dc, t, x_stop, -0.1, x_stop, 0.1);
		DrawLine2d(dc, t, x_stop / 2, -0.1, x_stop / 2, 0.1);
		DrawLine2d(dc, t, x_start, -0.1, x_start, 0.1);
		DrawLine2d(dc, t, x_start / 2, -0.1, x_start / 2, 0.1);
	}

	dc->SetPen(wxPen(RGB(29, 171, 32)));
	for (double x = x_min; x < x_max; x += dx)
		DrawLine2d(dc, t, x, GetFunctionValue(x), x + dx, GetFunctionValue(x + dx));
}

void ChartClass::DrawLine2d(wxDC* dc, Matrix t, double x1, double y1, double x2, double y2)
{
	Vector u, v;
	u.Set(x1, y1);
	v.Set(x2, y2);

	Vector uPrim = t * u;
	Vector vPrim = t * v;

	x1 = uPrim.GetX();
	y1 = uPrim.GetY();

	x2 = vPrim.GetX();
	y2 = vPrim.GetY();

	dc->DrawLine(x1, y1, x2, y2);
}

void ChartClass::DrawTxt(wxDC* dc, Matrix t, double alpha, double x, double y, double value)
{
	Vector txtPos;

	txtPos.Set(x, y);
	txtPos = t * txtPos;

	dc->DrawRotatedText(wxString::Format(wxT("%.2f"), value), txtPos.GetX(), txtPos.GetY(), alpha);
}


Matrix ChartClass::GetScaleMatrix(double w, double h, double x0, double x1, double y0, double y1)
{
	Matrix result;

	double sx = w / (x1 - x0);
	double sy = -h / (y1 - y0);

	result.data[0][0] = sx;
	result.data[1][1] = sy;

	return result;
}

Matrix ChartClass::GetRotationMatrix(double alpha)
{
	Matrix result;

	alpha *= M_PI / 180.0;

	result.data[0][0] = cos(alpha);
	result.data[0][1] = -sin(alpha);

	result.data[1][0] = sin(alpha);
	result.data[1][1] = cos(alpha);

	return result;
}

Matrix ChartClass::GetTranslationMatrix(double dx, double dy)
{
	Matrix result;

	result.data[0][0] = 1;
	result.data[1][1] = 1;

	result.data[0][2] = dx;
	result.data[1][2] = dy;

	return result;
}

double ChartClass::Get_Y_min()
{
	Set_Range();
	return y_min;
}

double ChartClass::Get_Y_max()
{
	Set_Range();
	return y_max;
}
