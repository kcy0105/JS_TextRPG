#pragma once

class CPlayer;

class CStore
{
private:
	CPlayer* m_pPlayer;

public:
	CStore() : m_pPlayer(nullptr) {}
	~CStore() { Release(); }

public:
	void Initialize();
	void Update();
	void Release();

public:
	void SetPlayer(CPlayer* pPlayer) { m_pPlayer = pPlayer; }
};

