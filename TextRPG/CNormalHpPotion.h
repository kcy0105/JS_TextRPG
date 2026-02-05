#pragma once
#include "CPotion.h"
#include "Define.h"

class CPlayer;

class CNormalHpPotion : public CPotion
{
public:
	virtual void Use(CPlayer* pPlayer);

public:
	CNormalHpPotion() : CPotion(PT_NORMAL_HP) 
	{
		m_szName = NORMAL_HP_POTION_NAME;
		m_iPrice = NORMAL_POTION_PRICE;
	}
};