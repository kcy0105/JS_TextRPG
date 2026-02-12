#pragma once
#include "CCreature.h"

class CMonster : public CCreature
{
protected:
	int m_iMonsterType;
	int m_iLoot;

public:
	CMonster(int iMonsterType) : CCreature(ET_MONSTER), m_iMonsterType(iMonsterType), m_iLoot(0)
	{
	}

};

