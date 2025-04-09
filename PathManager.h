#pragma once

#include <string>

class PathManager
{
public:
	static std::string GetAssetPath(const std::string& fileName);

	static std::string GetDataPath();

	static std::string GetCurrentPath();

private:
};