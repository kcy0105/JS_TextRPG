#pragma once
#include "CEquipment.h"
#include "CPlayer.h"

class CArmor : public CEquipment
{
protected:
	int m_iMaxHpIncrement;

public:
	virtual void Equip(CPlayer* pPlayer) {
		pPlayer->EquipItem(IT_ARMOR, this);
		pPlayer->SetMaxHp(m_iMaxHpIncrement);
	}
	virtual void Unequip(CPlayer* pplayer) {
		pplayer->UnequipItem(IT_ARMOR);
	}

	CArmor(int iEquipRarity) : CEquipment(IT_ARMOR, iEquipRarity), m_iMaxHpIncrement(0)
	{
		switch (iEquipRarity)
		{
		case ER_NORMAL:
			m_szName = BASIC_ARMOR_NAME + " " + EQUIP_NORMAL_SUFFIX;
			m_iMaxHpIncrement = ARMOR_NORMAL_MAX_HP_INCREMENT;
			m_iPrice = NORMAL_ITEM_PRICE;
			break;
		case ER_RARE:
			m_szName = BASIC_ARMOR_NAME + " " + EQUIP_RARE_SUFFIX;
			m_iMaxHpIncrement = ARMOR_RARE_MAX_HP_INCREMENT;
			m_iPrice = RARE_ITEM_PRICE;
			break;
		case ER_EPIC:
			m_szName = BASIC_ARMOR_NAME + " " + EQUIP_EPIC_SUFFIX;
			m_iMaxHpIncrement = ARMOR_EPIC_MAX_HP_INCREMENT;
			m_iPrice = EPIC_ITEM_PRICE;
			break;
		}
	}
};

