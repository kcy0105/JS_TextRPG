#pragma once
#include "CMonster.h"
#include "Define.h"

class CNormalMonster : public CMonster
{
public:
	CNormalMonster() : CMonster(MT_NORMAL)
	{
		m_szName = NORMAL_MONSTER_NAME;
		m_iHp = NORMAL_MONSTER_HP;
		m_iMaxHp = NORMAL_MONSTER_HP;
		m_iAtk = NORMAL_MONSTER_ATK;
	}
};

