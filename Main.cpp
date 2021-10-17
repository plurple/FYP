#include <chrono>
#include "Utility.h"
#include "StackFSM.h"

int main()
{
	Utility::startTime = std::chrono::steady_clock::now();

	StackFSM stack;

	stack.Run();

	return 0;
}