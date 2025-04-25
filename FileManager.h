#pragma once
#include "pch.h"
#include <string>

class Character;

class FileManager
{
public:
	std::string GetAssetPath(const std::string& fileName);
	std::string GetDataPath();
	std::string GetSavePath();
	std::string GetCurrentPath();
	void Save(Character* pPlayer);
	void Load(Character* pPlayer);
};