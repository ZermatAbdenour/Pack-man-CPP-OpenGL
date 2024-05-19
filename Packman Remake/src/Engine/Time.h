#pragma once
#include"GLFW/glfw3.h"
#include <chrono>
static class Time {
public:
	static double s_deltaTime;
	static double s_time;

	static void StartFrame() {
		s_time = glfwGetTime();
	}
	static void EndFrame() {
		s_deltaTime = glfwGetTime() - s_time;
	}

	class Timer {
	public:
		Timer() : start_time_point(std::chrono::high_resolution_clock::now()) {}
		Timer(double timeInSeconds) : start_time_point(std::chrono::high_resolution_clock::now()), m_timeInSeconds(timeInSeconds) {}
		void Reset();
		double elapsed() const;
		double elapsedSeconds() const;
		bool IsEnded();
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> start_time_point;
		double m_timeInSeconds;
	};
};