#pragma once
#include"Window.h"
#include"TinyTimer.h"
#include"ImguiManager.h"
#include "Camera.h"

class App {
public	:
	App();
	int Go();	
	~App();
private:
	void DoFrame();
private:
	ImguiManager imgui;
	Window window;
	TinyTimer timer;
	std::vector<std::unique_ptr<class Drawable>> drawables;
	float speed_factor = 1.0f;
	Camera cam;
	static constexpr size_t nDrawables = 180;
};