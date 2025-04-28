#pragma once
#include "ItemInfo.h"
#include <optional>

struct Stats
{
	int m_iAttack;
	int m_iHealth;
};

struct Effects
{
	int m_iHeal;
};

class Item
{
public:
	short m_iId;

	std::string m_strName;
	short m_sAmount;
	short m_sPrice;

	bool m_bIsEquip = false;
	
	std::optional<JOB_TYPES> m_eJob;
	std::optional<Stats> m_tStats;
	std::optional<Effects> m_tEffects;

	Item() = default;
};

inline void to_json(json& j, const Stats& stats)
{
    j = json{
        {"m_iAttack", stats.m_iAttack},
        {"m_iHealth", stats.m_iHealth}
    };
}

inline void from_json(const json& j, Stats& stats)
{
    j.at("m_iAttack").get_to(stats.m_iAttack);
    j.at("m_iHealth").get_to(stats.m_iHealth);
}

inline void to_json(json& j, const Effects& effects)
{
    j = json{
        {"m_iHeal", effects.m_iHeal}
    };
}

inline void from_json(const json& j, Effects& effects)
{
    j.at("m_iHeal").get_to(effects.m_iHeal);
}

inline void to_json(json& j, const Item& item)
{
    j = json{
        {"m_iId", item.m_iId},
        {"m_strName", item.m_strName},
        {"m_sAmount", item.m_sAmount},
        {"m_sPrice", item.m_sPrice},
        {"m_bIsEquip", item.m_bIsEquip},
    };

    if (item.m_eJob) j["m_eJob"] = item.m_eJob.value();
    if (item.m_tStats) j["m_tStats"] = item.m_tStats.value();
    if (item.m_tEffects) j["m_tEffects"] = item.m_tEffects.value();
}

inline void from_json(const json& j, Item& item)
{
    j.at("m_iId").get_to(item.m_iId);
    j.at("m_strName").get_to(item.m_strName);
    j.at("m_sAmount").get_to(item.m_sAmount);
    j.at("m_sPrice").get_to(item.m_sPrice);
    j.at("m_bIsEquip").get_to(item.m_bIsEquip);

    if (j.contains("m_eJob") && !j["m_eJob"].is_null())
        item.m_eJob = j["m_eJob"].get<JOB_TYPES>();

    if (j.contains("m_tStats") && !j["m_tStats"].is_null())
        item.m_tStats = j["m_tStats"].get<Stats>();

    if (j.contains("m_tEffects") && !j["m_tEffects"].is_null())
        item.m_tEffects = j["m_tEffects"].get<Effects>();
}