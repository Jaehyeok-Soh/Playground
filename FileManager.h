#pragma once

#include <string>

#include "Charactor.h"

class FileManager
{
public:
	std::string GetAssetPath(const std::string& fileName);
	std::string GetDataPath();
	std::string GetSavePath();
	std::string GetCurrentPath();
	void Save(Charactor* pPlayer);
	void Load(Charactor* pPlayer);

private:
};