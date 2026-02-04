#pragma once
#include "CPotion.h"
#include "Define.h"

class CPlayer;

class CMaxHpPotion : public CPotion
{
public:
	virtual void Use(CPlayer* pPlayer);

public:
	CMaxHpPotion() : CPotion(PT_MAX_HP) 
	{
		m_szName = MAX_HP_POTION_NAME;
		m_iPrice = MAXHP_POTION_PRICE;	// 포션가격 추가
	}
};