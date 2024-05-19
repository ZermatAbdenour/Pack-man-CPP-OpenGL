#include"Time.h"

double Time::s_deltaTime = 0;
double Time::s_time = 0;

void Time::Timer::Reset()
{
	start_time_point = std::chrono::high_resolution_clock::now();
}

double Time::Timer::elapsed() const
{
	auto end_time_point = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time_point - start_time_point).count();
	return duration * 0.001; // Return milliseconds
}

double Time::Timer::elapsedSeconds() const
{
	auto end_time_point = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time_point - start_time_point).count();
	return duration;
}

bool Time::Timer::IsEnded()
{
	return elapsedSeconds() > m_timeInSeconds;
}
