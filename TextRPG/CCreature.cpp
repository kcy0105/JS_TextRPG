#include "pch.h"
#include "CCreature.h"

void CCreature::PrintInfo()
{
	cout << m_szName << "\t체력: " << m_iHp << "/" << m_iMaxHp << "\t공격력: " << m_iAtk << endl;
}

void CCreature::OnAttacked(CCreature* pAttacker)
{
	cout << pAttacker->GetName() << "이(가) " << m_szName << "에게 " << pAttacker->GetAtk() << "의 피해를 주었습니다." << endl;
	m_iHp -= pAttacker->GetAtk();
	if (m_iHp < 0)
		m_iHp = 0;
}