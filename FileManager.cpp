#include "pch.h"
#include "FileManager.h"
#include "Character.h"
#include "Define.h"
#include "Item.h"

std::string FileManager::GetAssetPath(const std::string& fileName)
{
	return "assets\\" + fileName;
}

std::string FileManager::GetDataPath()
{
	return "assets\\data.json";
}

DATA_JSON FileManager::GetPath()
{
	std::ifstream inFile(GetDataPath());
	DATA_JSON jsonData;

	if (!inFile.is_open())
	{
		cout << "file stream error\n";
		return jsonData;
	}

	json j;
	inFile >> j;
	jsonData = j.get<DATA_JSON>();

	inFile.close();

	return jsonData;
}

void FileManager::Save(Character* pPlayer)
{
	Player* player = dynamic_cast<Player*>(pPlayer);
	json j = *player;

	//std::ofstream outFile(GetSavePath());
	std::ofstream outFile(GetPath().save_path, std::ios::out | std::ios::binary);
	if (!outFile)
	{
		cout << "file stream error\n";
		return;
	}

	outFile << j.dump(4, ' ', false, json::error_handler_t::ignore);
	outFile.close();

	cout << "저장 완료\n";
}

void FileManager::Load(Character* pPlayer)
{
	//std::ifstream inFile(GetSavePath());
	std::ifstream inFile(GetPath().save_path, std::ios::in | std::ios::binary);

	if (!inFile.is_open())
	{
		cout << "file stream error\n";
	}

	json j;
	inFile >> j;
	
	//TODO: 20250425
	//nlohmann::json ANSI > UTF-8 인코딩 이슈 
	Player player = j.get<Player>();
	player.Set_Job(player.Get_Job());
	*pPlayer = player;

	cout << "불러오기 완료\n";
}

std::vector<Item> FileManager::LoadItemList()
{
	std::ifstream inFile(GetPath().item_path, std::ios::in | std::ios::binary);

	if (!inFile.is_open())
	{
		cout << "file stream error\n";
	}

	json j;
	inFile >> j;
	
	return j.get<std::vector<Item>>();
}

std::string FileManager::GetCurrentPath()
{
	char path[_MAX_PATH];
	GetModuleFileNameA(NULL, path, MAX_PATH);
	return std::string(path);
}