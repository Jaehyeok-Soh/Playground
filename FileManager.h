#pragma once
#include "pch.h"
#include <string>

class FileManager
{
public:
	std::string GetDataPath();
	DATA_JSON GetPath();
	std::string GetCurrentPath();
	
	void Save(Character* pPlayer);
	void Load(Character* pPlayer);

	std::vector<Item> LoadItemList();

private:
	std::string GetAssetPath(const std::string& fileName);
};