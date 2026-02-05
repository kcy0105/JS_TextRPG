#pragma once
#include "CCreature.h"
#include "Define.h"
#include <cstring>

class CItem;

class CPlayer : public CCreature
{
private:
	int m_iMoney;
	int m_iItemCount[IT_COUNT];
	CItem* m_pItem[IT_COUNT][ITEM_MAX_COUNT];

public:
	CPlayer() : CCreature(ET_PLAYER), m_iMoney(0), m_iItemCount{}, m_pItem{}
	{
		m_szName = "플레이어";
		m_iHp = PLAYER_INITIAL_MAX_HP;
		m_iMaxHp = PLAYER_INITIAL_MAX_HP;
		m_iAtk = PLAYER_INITIAL_ATK;
	}

public:
	void AddHp(int iValue);

	void SetHpToMax();

	bool SelectPotion(); 

	void UsePotion(int iIndex);
	void AddItem(CItem* pItem);

};