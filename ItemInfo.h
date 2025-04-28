#pragma once
namespace ItemInfo
{
	/// <summary>
	/// - 100 ~ Consumable
	/// - 200 ~ weapon
	/// - 300 ~ armour
	/// </summary>
	enum TYPE : int
	{
		CONSUMABLE				= 100,
		WEAPON					= 200,
		ARMOUR					= 300,
	};

	/// <summary>
	/// - 100 ~ Consumable
	/// - 200 ~ weapon
	/// - 300 ~ armour
	/// </summary>
	enum CODE : int
	{
		/// - 100 ~ Consumable
		HEALING_POSTION			= static_cast<int>(TYPE::CONSUMABLE) + 0,

		/// - 200 ~ weapon
		SWORD_N					= static_cast<int>(TYPE::WEAPON) + 0,
		STICK_N,
		DAGGER_N,

		/// - 300 ~ armour
		EQUIP_ARMOUR_N			= static_cast<int>(TYPE::ARMOUR) + 0,
	};

	constexpr TYPE TypeCvt(CODE _eCode)
	{
		int iValue = static_cast<int>(_eCode);
		if (iValue > 200)
			return TYPE::CONSUMABLE;
		else if (iValue > 300)
			return TYPE::WEAPON;
		else if (iValue > 400)
			return TYPE::ARMOUR;
	}
}