#pragma once
#include"Window.h"
#include"TinyTimer.h"

class App {
public	:
	App();
	int Go();	
	~App();
private:
	void DoFrame();
private:
	Window window;
	TinyTimer timer;
	std::vector<std::unique_ptr<class Drawable>> drawables;
	static constexpr size_t nDrawables = 180;
};