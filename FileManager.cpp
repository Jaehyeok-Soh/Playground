#include "pch.h"

#include "FileManager.h"

using namespace std;
using json = nlohmann::json;

std::string FileManager::GetAssetPath(const std::string& fileName)
{
	return "assets\\" + fileName;
}

std::string FileManager::GetDataPath()
{
	return "assets\\data.json";
}

std::string FileManager::GetSavePath()
{
	if (pFile == nullptr)
	{
		//err = fopen_s(&pFile, GetDataPath(), "rt");
	}

	return "assets\\save.json";
}

std::string FileManager::GetCurrentPath()
{
	char path[_MAX_PATH];
	GetModuleFileNameA(NULL, path, MAX_PATH);
	return std::string(path);
}