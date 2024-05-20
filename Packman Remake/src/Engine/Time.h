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
		Timer() : m_startTime(std::chrono::high_resolution_clock::now()) {}
		Timer(double timeInMS) : m_startTime(std::chrono::high_resolution_clock::now()), m_timeInMS(timeInMS) {}
		void Reset();
		double elapsed() const;
		double elapsedSeconds() const;
		bool IsEnded();
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
		double m_timeInMS;
	};
};