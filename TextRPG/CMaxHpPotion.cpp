#include "pch.h"
#include "CMaxHpPotion.h"
#include "CPlayer.h"

void CMaxHpPotion::Use(CPlayer* pPlayer)
{
	pPlayer->SetHpToMax();
	cout << m_szName << "을 사용하여 체력을 최대로 회복했습니다." << endl;
}
