#include "CField.h"
#include "CMonster.h"
#include "CEasyMonster.h"
#include "CPlayer.h"

#include "Define.h"
#include "pch.h"

void CField::Initialize()
{
	
}

void CField::Update()
{
	// TEST
	CMonster* pMonster = new CEasyMonster();
	Fight(pMonster);
}

void CField::Release()
{
}

int CField::Fight(CMonster* pMonster)
{
	cout << "앗! 야생의 " << pMonster->GetName() << "을(를) 발견했다!" << endl;
	system("pause");

	int iInput;

	while (true)
	{
		// 플레이어 턴
		system("cls");
		m_pPlayer->PrintInfo();
		pMonster->PrintInfo();
		
		cout << "당신의 턴입니다." << endl;
		bool bTurnFinished = false;

		while (true) // 포션 미선택 시 다시 선택해야 하므로 while문 사용
		{
			cout << "1. 공격 2. 도망 3. 포션 사용" << endl;
			cin >> iInput;
			switch (iInput)
			{
			case 1:
				pMonster->OnAttacked(m_pPlayer);

				if (pMonster->IsDead())
				{
					system("cls");
					m_pPlayer->PrintInfo();
					pMonster->PrintInfo();
					cout << pMonster->GetName() << "을(를) 해치웠습니다!" << endl;
					system("pause");
					system("cls");
					SAFE_DELETE(pMonster);
					return FR_WIN;
				}

				bTurnFinished = true;

				break;
			case 2:
				cout << "비겁하게 도망을 선택했다.." << endl;
				system("pause");
				system("cls");
				return FR_RUN;
			case 3:
				if (m_pPlayer->SelectPotion())
					bTurnFinished = true;
				break;
			}

			if (bTurnFinished) break;
		}
		

		system("pause");

		// 몬스터 턴
		system("cls");
		m_pPlayer->PrintInfo();
		pMonster->PrintInfo();
		cout << "적의 턴입니다." << endl;
		system("pause");
		m_pPlayer->OnAttacked(pMonster);
		system("pause");
		if (m_pPlayer->IsDead())
		{
			system("cls");
			m_pPlayer->PrintInfo();
			pMonster->PrintInfo();
			cout << pMonster->GetName() << "의 일격에 당신은 죽고 말았습니다.." << endl;
			system("pause");
			system("cls");
			m_pPlayer->SetHpToMax();
			return FR_LOSE;
		}
	}

	return 0;
}
