#pragma once

#include "pch.h"

#include <string>

class FileManager
{
public:
	FILE* pFile = nullptr;
	errno_t err;

	std::string GetAssetPath(const std::string& fileName);
	std::string GetDataPath();
	std::string GetSavePath();
	std::string GetCurrentPath();

private:
};