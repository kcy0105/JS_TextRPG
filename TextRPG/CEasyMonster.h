#pragma once
#include "CMonster.h"

class CEasyMonster : public CMonster
{
public:
	CEasyMonster() : CMonster(MT_EASY)
	{
		m_szName = EASY_MONSTER_NAME;
		m_iHp = EASY_MONSTER_HP;
		m_iMaxHp = EASY_MONSTER_HP;
		m_iAtk = EASY_MONSTER_ATK;
	}
};

