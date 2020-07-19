#pragma once
#include"Window.h"
#include"TinyTimer.h"

class App {
public	:
	App();
	int Go();
private:
	void DoFrame();
private:
	Window window;
	TinyTimer timer;
};