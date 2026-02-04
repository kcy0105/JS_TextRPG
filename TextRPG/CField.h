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
	void SetPlayer(CPlayer* pPlayer) { m_pPlayer = pPlayer; }

private:
	int Fight(CMonster* pMonster);
};

