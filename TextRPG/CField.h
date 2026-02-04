#pragma once
#include "CEntity.h"

class CPlayer;

class CField
{
private:
	static const int iMonCnt = 3;
	static const int iMapXLen = 10;
	static const int iMapYLen = 5;
	CEntity* m_pPlayer;
	// CEntity* m_pMonArr[iMonCnt];
	CEntity* m_Map[iMapYLen][iMapXLen];

public:
	CField();
	~CField() { Release(); }

public:
	void Initialize();
	void Update();
	void Release();

public:
	void	Render();
	void	SetPlayer(CEntity* pPlayer) { m_pPlayer = pPlayer; };
	bool	OnMovement(int targetPosX, int targetPosY);
	int		Fight(CEntity* pMonster);

};

