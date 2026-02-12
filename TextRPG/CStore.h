#pragma once

class CPlayer;
class CItem;

struct ItemInfo {
	string szName;
	int iPrice;
	CItem* (*factory)();
};


class CStore
{
private:
	CPlayer* m_pPlayer;
	vector<ItemInfo> vecItemList[IT_COUNT];

public:
	CStore() : m_pPlayer(nullptr) {}
	~CStore() { Release(); }

public:
	void Initialize();
	void Update();
	void Release();

	void Render(int	ItemType);

public:
	void SetPlayer(CPlayer* pPlayer) { m_pPlayer = pPlayer; }
};

