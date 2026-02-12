#pragma once

class CPlayer;

class CInventory
{
private:
	CPlayer* m_pPlayer;

public:
	CInventory() : m_pPlayer(nullptr) {}
	~CInventory() { Release(); }

public:
	void Initialize();
	void Update();
	void Release();

	void Render(int ItemType);

public:
	void SetPlayer(CPlayer* pPlayer) { m_pPlayer = pPlayer; }
};

