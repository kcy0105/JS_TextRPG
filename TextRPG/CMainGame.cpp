#include "CMainGame.h"
#include "CPlayer.h"
#include "CField.h"
#include "CStore.h"
#include "CInventory.h"
#include "pch.h"

void CMainGame::Initialize()
{
	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
	}

	if (!m_pField)
	{
		m_pField = new CField;
		// m_pField->Initialize(); 입장 시 Initialize
	}

	m_pField->SetPlayer(m_pPlayer);

	if (!m_pStore)
	{
		m_pStore = new CStore;
		m_pStore->Initialize();
	}

	m_pStore->SetPlayer(m_pPlayer);

	if (!m_pInventory)
	{
		m_pInventory = new CInventory;
		m_pInventory->Initialize();
	}

	m_pInventory->SetPlayer(m_pPlayer);
}

void CMainGame::Update()
{
	int iInput;

	while (true)
	{
		cout << "---------------[마을]---------------" << endl;
		cout << "1. 사냥터 2. 상점 3. 인벤토리 4. 종료" << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			if (m_pField)
				m_pField->Initialize();
				m_pField->Update();
			break;
		case 2:
			if (m_pStore)
				m_pStore->Update();
			break;
		case 3:
			if (m_pInventory)
				m_pInventory->Update();
			break;
		case 4:
			return;
		}
	}
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pField);
	SAFE_DELETE(m_pStore);
	SAFE_DELETE(m_pInventory);
	SAFE_DELETE(m_pPlayer);
}
