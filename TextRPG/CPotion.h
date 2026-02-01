#pragma once
#include "CItem.h"
#include "Define.h"

class CPlayer;

class CPotion : public CItem
{
private:
	int m_iPotionType;

public:
	virtual void Use(CPlayer* pPlayer) = 0;

	CPotion(int iPotionType) : CItem(IT_POTION), m_iPotionType(iPotionType) {}
};