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
	CItem* m_pItemSlot[IT_COUNT];

	bool bIncrement = false;

public:
	CPlayer() : CCreature(ET_PLAYER), m_iMoney(0), m_iItemCount{}, m_pItem{}
	{
		m_szName = "플레이어";
		m_iHp = PLAYER_INITIAL_MAX_HP;
		m_iMaxHp = PLAYER_INITIAL_MAX_HP;
		m_iAtk = PLAYER_INITIAL_ATK;

		m_iMoney = 10000;	// 첫 소지금 1만원(TEST용)
		memset(&m_pItemSlot, 0, sizeof(m_pItemSlot));
	}

public:
	void AddHp(int iValue);
	 
	void SetHpToMax();

	bool SelectPotion(); 

	void UsePotion(int iIndex);
	void AddItem(CItem* pItem);

	int GetMoney() { return m_iMoney; }
	void SetMoney(int UsedMoney) { m_iMoney -= UsedMoney; }

	// void ManagementMoney(CPlayer* playerMoney, int UsedMoney);	// 돈관리용(이 방식 너무 구림.. 위 get,set으로 변경)

	int GetItemCount(int ItemType) { return m_iItemCount[ItemType]; }
	CItem* GetItem(int ItemType, int iIndex) { return m_pItem[ItemType][iIndex]; }

	void EquipItem(int ItemType, CItem* pItem);
	void UnequipItem(int ItemType);

	void SetAtk(int iAtk) { m_iAtk += iAtk; }
	void SetMaxHp(int iHp) { m_iMaxHp += iHp; }
};