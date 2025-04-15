#pragma once

#include <string>

#include "Character.h"

class FileManager
{
public:
	std::string GetAssetPath(const std::string& fileName);
	std::string GetDataPath();
	std::string GetSavePath();
	std::string GetCurrentPath();
	void Save(Character* pPlayer);
	void Load(Character* pPlayer);

private:
};