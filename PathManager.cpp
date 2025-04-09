#include "pch.h"

#include "PathManager.h"

using namespace std;
using json = nlohmann::json;

std::string PathManager::GetAssetPath(const std::string& fileName)
{
	return "assets\\" + fileName;
}

std::string PathManager::GetDataPath()
{
	return "assets\\data.json";
}

std::string PathManager::GetCurrentPath()
{
	char path[_MAX_PATH];
	GetModuleFileNameA(NULL, path, MAX_PATH);
	return std::string(path);
}