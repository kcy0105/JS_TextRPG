#include "CStore.h"
#include "CPlayer.h"
#include "CNormalHpPotion.h"
#include "CMaxHpPotion.h"

void CStore::Initialize()
{
}

void CStore::Update()
{
	// TEST
	m_pPlayer->AddItem(new CNormalHpPotion);
	m_pPlayer->AddItem(new CMaxHpPotion);
}

void CStore::Release()
{
}
