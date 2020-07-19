#include "TinyTimer.h"

using namespace std::chrono;

TinyTimer::TinyTimer() 
{
	last = steady_clock::now();
}

float TinyTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float TinyTimer::Peek() const
{
	return duration<float>(steady_clock::now() - last).count();
}

