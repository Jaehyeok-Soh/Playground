#include "pch.h"

int main()
{
	bool bIsQuit = false;

	RendererService renderer;
	Management tagManagement = Management(&renderer);

	while (!bIsQuit)
	{
		bIsQuit = tagManagement.Start();
	}

	tagManagement.Quit();

	return 0;
}