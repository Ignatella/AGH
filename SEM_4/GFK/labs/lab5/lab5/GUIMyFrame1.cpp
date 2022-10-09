#include "GUIMyFrame1.h"
#include <vector>
#include <fstream>
#include "vecmat.h"
#include <iostream>
#include <glm/glm.hpp> // vec3, vec4, ivec4, mat4
#include <glm/gtc/matrix_transform.hpp> // translate, rotate, scale, perspective
#include <glm/gtc/type_ptr.hpp> // value_ptr

struct Point
{
	float x, y, z;
	Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

struct Color
{
	int R, G, B;
	Color(int _R, int _G, int _B) : R(_R), G(_G), B(_B) {}
};

struct Segment
{
	Point begin, end;
	Color color;
	Segment(Point _begin, Point _end, Color _color) : begin(_begin), end(_end), color(_color) {}
};

std::vector<Segment> data;

GUIMyFrame1::GUIMyFrame1(wxWindow* parent) : MyFrame1(parent)
{
	m_button_load_geometry->SetLabel(_("Wczytaj Geometrie"));
	m_staticText25->SetLabel(_("Obrot X:"));
	m_staticText27->SetLabel(_("Obrot Y:"));
	m_staticText29->SetLabel(_("Obrot Z:"));

	WxSB_TranslationX->SetRange(0, 200); WxSB_TranslationX->SetValue(100);
	WxSB_TranslationY->SetRange(0, 200); WxSB_TranslationY->SetValue(100);
	WxSB_TranslationZ->SetRange(0, 200); WxSB_TranslationZ->SetValue(100);

	WxSB_RotateX->SetRange(0, 360); WxSB_RotateX->SetValue(0);
	WxSB_RotateY->SetRange(0, 360); WxSB_RotateY->SetValue(0);
	WxSB_RotateZ->SetRange(0, 360); WxSB_RotateZ->SetValue(0);

	WxSB_ScaleX->SetRange(1, 200); WxSB_ScaleX->SetValue(100);
	WxSB_ScaleY->SetRange(1, 200); WxSB_ScaleY->SetValue(100);
	WxSB_ScaleZ->SetRange(1, 200); WxSB_ScaleZ->SetValue(100);

	//m_button_load_geometry_click(wxCommandEvent());
}

void GUIMyFrame1::WxPanel_Repaint(wxUpdateUIEvent& event)
{
	Repaint();
}

void GUIMyFrame1::m_button_load_geometry_click(wxCommandEvent& event)
{
	wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Geometry file (*.geo)|*.geo"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (WxOpenFileDialog.ShowModal() == wxID_OK)
	{
		double x1, y1, z1, x2, y2, z2;
		int r, g, b;

		std::ifstream in(WxOpenFileDialog.GetPath().ToAscii());
		// std::ifstream in("D:\\Desktop\\a10a_4.geo");
		if (in.is_open())
		{
			data.clear();
			while (!in.eof())
			{
				in >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> r >> g >> b;
				data.push_back(Segment(Point(x1, y1, z1), Point(x2, y2, z2), Color(r, g, b)));
			}
			in.close();
		}
	}
}

void GUIMyFrame1::Scrolls_Updated(wxScrollEvent& event)
{
	WxST_TranslationX->SetLabel(wxString::Format(wxT("%g"), (WxSB_TranslationX->GetValue() - 100) / 50.0));
	WxST_TranslationY->SetLabel(wxString::Format(wxT("%g"), (WxSB_TranslationY->GetValue() - 100) / 50.0));
	WxST_TranslationZ->SetLabel(wxString::Format(wxT("%g"), (WxSB_TranslationZ->GetValue() - 100) / 50.0));

	WxST_RotateX->SetLabel(wxString::Format(wxT("%d"), WxSB_RotateX->GetValue()));
	WxST_RotateY->SetLabel(wxString::Format(wxT("%d"), WxSB_RotateY->GetValue()));
	WxST_RotateZ->SetLabel(wxString::Format(wxT("%d"), WxSB_RotateZ->GetValue()));

	WxST_ScaleX->SetLabel(wxString::Format(wxT("%g"), WxSB_ScaleX->GetValue() / 100.0));
	WxST_ScaleY->SetLabel(wxString::Format(wxT("%g"), WxSB_ScaleY->GetValue() / 100.0));
	WxST_ScaleZ->SetLabel(wxString::Format(wxT("%g"), WxSB_ScaleZ->GetValue() / 100.0));


	Repaint();
}

glm::mat4 getM(glm::vec3 const& Translate, glm::vec3 const& Rotate, glm::vec3 const& Scale)
{
	glm::mat4 ViewTranslate = glm::translate(glm::mat4(1.0f), Translate);


	glm::mat4 Model = glm::rotate(ViewTranslate, Rotate.x, glm::vec3(1.0f, 0.0f, 0.0f));
	Model = glm::rotate(Model, Rotate.y, glm::vec3(0.0f, 1.0f, 0.0f));
	Model = glm::rotate(Model, Rotate.z, glm::vec3(0.0f, 1.0f, 1.0f));

	Model = glm::scale(Model, Scale);

	return Model;
}

void GUIMyFrame1::Repaint()
{
	wxClientDC dc1(WxPanel);
	wxBufferedDC dc(&dc1);
	dc.SetBackground(wxBrush(RGB(255, 255, 255)));
	dc.Clear();

	double wx = WxPanel->GetSize().x;
	double wy = WxPanel->GetSize().y;

	float translationX = (WxSB_TranslationX->GetValue() - 100.0) / 50.0;
	float translationY = (WxSB_TranslationY->GetValue() - 100.0) / 50.0;
	float translationZ = (WxSB_TranslationZ->GetValue() - 100.0) / 50.0;

	float angleX = glm::radians(static_cast<float>(360.f - WxSB_RotateX->GetValue()));
	float angleY = glm::radians(static_cast<float>(WxSB_RotateY->GetValue()));
	float angleZ = glm::radians(static_cast<float>(WxSB_RotateZ->GetValue()));

	float scaleX = WxSB_ScaleX->GetValue() / 100.f;
	float scaleY = WxSB_ScaleY->GetValue() / 100.f;
	float scaleZ = WxSB_ScaleZ->GetValue() / 100.f;

	auto m = getM(
		glm::vec3(-translationX, translationY, 1.1 + translationZ),
		glm::vec3(angleX, angleY, angleZ),
		glm::vec3(scaleX, scaleY, scaleZ)
	);

	for (const auto& segment : data)
	{
		dc.SetPen(wxPen(RGB(segment.color.R, segment.color.G, segment.color.B)));

		auto s = glm::vec4(segment.begin.x, segment.begin.y, segment.begin.z, 1.f);
		auto e = glm::vec4(segment.end.x, segment.end.y, segment.end.z, 1.f);

		auto sv = m * s;
		auto ev = m * e;

		auto clip_value = 0.1f;
		if ((sv.z > clip_value && ev.z <= clip_value) || (ev.z > clip_value && sv.z <= clip_value))
		{
			glm::vec4 outside = ev.z <= clip_value ? ev : sv;
			glm::vec4 inside = ev.z <= clip_value ? sv : ev;

			double r = abs((clip_value - outside.z) / (inside.z - outside.z));
			outside.x = (inside.x - outside.x) * r + outside.x;
			outside.y = (inside.y - outside.y) * r + outside.y;
			outside.z = clip_value;

			sv = outside;
			ev = inside;
		} else if (sv.z <= clip_value && ev.z <= clip_value)
		{
			continue;
		}

		glm::mat4 Projection = glm::perspective(glm::radians(90.0f), (float)(wx / wy), 0.1f, 100.0f);

		sv = Projection * sv;
		ev = Projection * ev;

		sv.x /= sv.w;
		sv.y /= sv.w;
		sv.z /= sv.w;

		ev.x /= ev.w;
		ev.y /= ev.w;
		ev.z /= ev.w;

		auto ViewScaled = glm::scale(glm::mat4(1.0f), glm::vec3(wx / 2.0f, wy / 2.0f, 1));
		auto LookAt = glm::lookAtLH(glm::vec3(0, 0, 0), glm::vec3(0, 0, 1.1), glm::vec3(0, 1, 0));

		sv = LookAt * ViewScaled * sv;
		ev = LookAt * ViewScaled * ev;

		dc.DrawLine(sv.x + wx / 2.0f, sv.y + wy / 2.0f, ev.x + wx / 2.0f, ev.y + wy / 2.0f);
	}
}
