#pragma once
#include "CEquipment.h"
#include "CPlayer.h"

class CWeapon : public CEquipment
{
private:
	int m_iAtkIncrement;

public:
	virtual void Equip(CPlayer* pPlayer)
	{
		pPlayer->EquipItem(IT_WEAPON, this);
		pPlayer->SetAtk(m_iAtkIncrement);
	}
	virtual void Unequip(CPlayer* pplayer) {
		pplayer->SetAtk(-m_iAtkIncrement);
		//pplayer->UnequipItem(IT_WEAPON);
	}

	CWeapon(int iEquipRarity) : CEquipment(IT_WEAPON, iEquipRarity), m_iAtkIncrement(0)
	{
		switch (iEquipRarity)
		{
		case ER_NORMAL:
			m_szName = BASIC_WEAPON_NAME + " " + EQUIP_NORMAL_SUFFIX;
			m_iAtkIncrement = WEAPON_NORMAL_ATK_INCREMENT;
			m_iPrice = NORMAL_ITEM_PRICE;	// 가격정보 추가
			break;
		case ER_RARE:
			m_szName = BASIC_WEAPON_NAME + " " + EQUIP_RARE_SUFFIX;
			m_iAtkIncrement = WEAPON_RARE_ATK_INCREMENT;
			m_iPrice = RARE_ITEM_PRICE;
			break;
		case ER_EPIC:
			m_szName = BASIC_WEAPON_NAME + " " + EQUIP_EPIC_SUFFIX;
			m_iAtkIncrement = WEAPON_EPIC_ATK_INCREMENT;
			m_iPrice = EPIC_ITEM_PRICE;
			break;
		}
	}
};

