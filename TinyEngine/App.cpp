#include "App.h"
#include <sstream>
#include <iomanip>

App::App() :
	window(800, 600, "TinyEngine") {}

int App::Go()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
			return *ecode;
		DoFrame();
	}
}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	window.Gfx().ClearBuffer(c, c, 1.0f);
	window.Gfx().DrawTestTriangle(
		-timer.Peek(),
		0.0f,
		0.0f
	);
	window.Gfx().DrawTestTriangle(
		timer.Peek(),
		window.mouse.GetPosX() / 400.0f - 1.0f,
		-window.mouse.GetPosY() / 300.0f + 1.0f
	);
	window.Gfx().EndFrame();
}

