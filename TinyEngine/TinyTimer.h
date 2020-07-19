#pragma once
#include <chrono>

class TinyTimer
{
public:
	TinyTimer();
	float Mark();
	float Peek() const;
private:
	std::chrono::steady_clock::time_point last;
};