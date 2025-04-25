#include "pch.h"

#include "FileManager.h"
#include "Character.h"
#include "Define.h"

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
	std::ifstream inFile(GetDataPath());
	Data jsonData;

	if (!inFile.is_open())
	{
		cout << "file stream error\n";
		return "";
	}

	json j;
	inFile >> j;
	jsonData = j.get<Data>();

	inFile.close();

	return jsonData.save_path;
}

void FileManager::Save(Character* pPlayer)
{
	Player* player = dynamic_cast<Player*>(pPlayer);
	json j = *player;

	//std::ofstream outFile(GetSavePath());
	std::ofstream outFile(GetSavePath(), std::ios::out | std::ios::binary);
	if (!outFile)
	{
		cout << "file stream error\n";
		return;
	}

	//cout << j.dump(4, ' ', false , json::error_handler_t::replace);

	outFile << j.dump(4, ' ', true, json::error_handler_t::ignore);
	outFile.close();

	cout << "���� �Ϸ�\n";
}

void FileManager::Load(Character* pPlayer)
{
	//std::ifstream inFile(GetSavePath());
	std::ifstream inFile(GetSavePath(), std::ios::in | std::ios::binary);

	if (!inFile.is_open())
	{
		cout << "file stream error\n";
	}

	json j;
	inFile >> j;
	
	//TODO: 20250425
	//nlohmann::json ANSI > UTF-8 ���ڵ� �̽� 
	Player player = j.get<Player>();
	player.Set_Job(player.Get_Job());
	*pPlayer = player;

	cout << "�ҷ����� �Ϸ�\n";
}

std::string FileManager::GetCurrentPath()
{
	char path[_MAX_PATH];
	GetModuleFileNameA(NULL, path, MAX_PATH);
	return std::string(path);
}