#include "pch.h"

#include "FileManager.h"
#include "Types.h"

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
	char cFileContents[100];

	JsonData jsonData;

	if (pFile == nullptr)
	{
		err = fopen_s(&pFile, GetDataPath().c_str(), "rt");
	}

	if (err == 0)
	{
		fgets(cFileContents, sizeof(cFileContents), pFile);

		json j = cFileContents;
		jsonData = j.get<JsonData>();
	}
	else
	{
		cout << "file stream error\n";
	}

	CloseFileStream();

	return jsonData.save_path;
}

void FileManager::Save(Charactor* pPlayer)
{
	const char* pSavePath = GetSavePath().c_str();

	json j = *pPlayer;

	if (pFile == nullptr)
	{
		err = fopen_s(&pFile, pSavePath, "wt");
	}

	if (err == 0)
	{
		fputs(j.dump(4).c_str(), pFile);
		cout << "저장 성공\n";
	}
	else
	{
		cout << "file stream error\n";
	}

	CloseFileStream();
}

void FileManager::Load(Charactor* pPlayer)
{
	const char* pSavePath = GetSavePath().c_str();
	char cLoadContents[100];
	json j;

	if (pFile == nullptr)
	{
		err = fopen_s(&pFile, pSavePath, "rt");
	}

	if (err == 0)
	{
		fgets(cLoadContents, sizeof(cLoadContents), pFile);
		j = cLoadContents;
		Charactor bufferData = j.get<Charactor>();
		*pPlayer = bufferData;

		cout << "load complete\n";
	}
	else
	{
		cout << "file stream error\n";
	}
}

std::string FileManager::GetCurrentPath()
{
	char path[_MAX_PATH];
	GetModuleFileNameA(NULL, path, MAX_PATH);
	return std::string(path);
}

void FileManager::CloseFileStream()
{
	fclose(pFile);
	pFile = nullptr;
}