#include "pch.h"

#include "FileManager.h"
#include "Define.h"
#include "SaveData.h"

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
	json j = *pPlayer;

	std::ofstream outFile(GetSavePath());

	if (!outFile)
	{
		cout << "file stream error\n";
		return;
	}

	outFile << j.dump(4);
	outFile.close();

	cout << "저장 성공\n";
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
	*pPlayer = j.get<Character>();

	cout << "불러오기 성공\n";
}

std::string FileManager::GetCurrentPath()
{
	char path[_MAX_PATH];
	GetModuleFileNameA(NULL, path, MAX_PATH);
	return std::string(path);
}