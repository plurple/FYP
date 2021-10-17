#pragma once
#include <random>
#include <chrono>

namespace Utility
{
	int RandomInt(int Min, int Max);

	using DWORD = unsigned long;

	static std::chrono::steady_clock::time_point startTime;
	DWORD GetTime();
}

