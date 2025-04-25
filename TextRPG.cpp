#include "pch.h"

int main()
{
	bool bIsQuit = false;

	Management tagManagement;

	while (!bIsQuit)
	{
		bIsQuit = tagManagement.Start();
	}

	tagManagement.Quit();

	return 0;
}