#pragma once

#include "CEntity.h"
#include "pch.h"
using namespace std;

class CCreature : public CEntity
{
protected:
	string m_szName;
	int m_iHp, m_iAtk, m_iMaxHp;

public:
	CCreature(int iEntityType) : CEntity(iEntityType), m_szName{}, m_iHp(0), m_iAtk(0), m_iMaxHp(0)
	{

	}

public:
	string GetName() { return m_szName; }
	int GetAtk() const { return m_iAtk; }
	bool IsDead() const { return m_iHp <= 0; }
	void PrintInfo();
	void OnAttacked(CCreature*);
};

