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

	std::ofstream outFile(GetSavePath());

	if (!outFile)
	{
		cout << "file stream error\n";
		return;
	}

	cout << j.dump(4);

	outFile << j.dump(4);
	outFile.close();

	cout << "���� ����\n";
}

void FileManager::Load(Character* pPlayer)
{
	std::ifstream inFile(GetSavePath());

	if (!inFile.is_open())
	{
		cout << "file stream error\n";
	}

	json j;
	inFile >> j;

	Player player = j.get<Player>();

	*pPlayer = player;

	cout << "�ҷ����� ����\n";
}

std::string FileManager::GetCurrentPath()
{
	char path[_MAX_PATH];
	GetModuleFileNameA(NULL, path, MAX_PATH);
	return std::string(path);
}