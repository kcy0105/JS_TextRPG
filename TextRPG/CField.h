#pragma once

class CPlayer;
class CMonster;

class CField
{
private:
	CPlayer* m_pPlayer;

public:
	CField() : m_pPlayer(nullptr) {}
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

private:
	int Fight(CMonster* pMonster);
};

