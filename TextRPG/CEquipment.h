#pragma once
#include "CItem.h"

class CPlayer;

class CEquipment : public CItem
{
private:
	int m_iEquipRarity;

public:
	virtual void Equip(CPlayer* pPlayer) = 0;

	CEquipment(int iItemType, int iEquipRarity) : CItem(iItemType), m_iEquipRarity(iEquipRarity)
	{
	}
};

