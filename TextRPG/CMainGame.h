#pragma once
class CPlayer;
class CField;
class CStore;
class CInventory;

class CMainGame
{
public:
	CMainGame() : m_pPlayer(nullptr), m_pField(nullptr), m_pStore(nullptr), m_pInventory(nullptr) { }
	~CMainGame() { Release(); }

public:
	void Initialize();
	void Update();
	void Release();

private:
	CPlayer* m_pPlayer;
	CField* m_pField;
	CStore* m_pStore;
	CInventory* m_pInventory;
};