#pragma once

#include "pch.h"
#include "Character.h"
#include "json.hpp"

using json = nlohmann::json;

/// <summary>
/// TODO: add time stamp
/// 250419
/// </summary>
class SaveData : public Character
{
public:
	//time_t tDateTime;

	//NLOHMANN_DEFINE_TYPE_INTRUSIVE(SaveData, tDateTime)

	SaveData() : Character()
	{
		//time(&tDateTime);
		//cout << ctime(&tDateTime);
	}
};

//void to_json(nlohmann::json& j, const SaveData& s) {
//	nlohmann::to_json(j, static_cast<Character>(s));
//	j.update({{"tDateTime", s.tDateTime}});
//}