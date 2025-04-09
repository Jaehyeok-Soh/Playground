// TextRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

using namespace std;

void main()
{
	bool bIsQuit = false;

	Management tagManagement;

	while (!bIsQuit)
	{
		bIsQuit = tagManagement.Start();
	}

	return;
}