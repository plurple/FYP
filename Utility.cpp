#include "Utility.h"

int Utility::RandomInt(int Min, int Max)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(Min, Max);
	return dist(rng);
}

Utility::DWORD Utility::GetTime()
{
	return (std::chrono::steady_clock::now() - startTime).count();
}