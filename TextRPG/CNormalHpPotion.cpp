#include "pch.h"
#include "CNormalHpPotion.h"
#include "CPlayer.h"

void CNormalHpPotion::Use(CPlayer* pPlayer)
{
	pPlayer->AddHp(NORMAL_HP_POTION_INCREMENT);
	cout << m_szName << "을 사용하여 체력을 " << NORMAL_HP_POTION_INCREMENT << " 회복했습니다." << endl;
}