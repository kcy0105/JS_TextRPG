#include "CField.h"
#include "Define.h"
#include "pch.h"
#include "CEasyMonster.h"
#include "CNormalMonster.h"
#include "CPlayer.h"

CField::CField() : m_pPlayer(nullptr)
{
}

void CField::Initialize()
{
	srand((unsigned)time(NULL));
	// CEntity* 이차원 배열 만들기 및 몬스터 앞에서부터 채우기
	for (int i = 0; i < iMapYLen; ++i)
	{
		for (int j = 0; j < iMapXLen; ++j)
		{
			if (i * iMapXLen + j < iMonCnt)
			{
				// 몬스터 난이도 랜덤 생성
				if (rand()%2)
					m_Map[i][j] = new CEasyMonster();
				else 
					m_Map[i][j] = new CNormalMonster();
			}
			else
				m_Map[i][j] = nullptr;
		}
	}
	// 맵 100회 셔플
	for (int i = 0; i < 100; ++i)
	{
		// 포탈, 플레이어 위치 제외하기
		int randNumX1 = rand() % iMapXLen;
		int randNumY1 = rand() % iMapYLen;
		int randNumX2 = rand() % iMapXLen;
		int randNumY2 = rand() % iMapYLen;

		if (randNumX1 <= 1 && randNumY1 == iMapYLen / 2)
			continue;

		swap(m_Map[randNumY1][randNumX1], m_Map[randNumY2][randNumX2]);
	}

	// 셔플된 위치로 CEntity*의 위치값 재조정
	for (int i = 0; i < iMapYLen; ++i)
	{
		for (int j = 0; j < iMapXLen; ++j)
		{
			if (m_Map[i][j] != nullptr)
			m_Map[i][j]->MovePos(i, j);
		}
	}

	//플레이어 위치 설정
	m_pPlayer->MovePos(1, iMapYLen / 2);
	m_Map[iMapYLen / 2][1] = m_pPlayer;

	// 포탈 위치 설정
	m_Map[iMapYLen / 2][0] = new CEntity(ET_PORTAL); // 몬스터와 같이 해제 할 것.
}

void CField::Update()
{
	while (1)
	{
		system("cls");
		Render();
		int iInput;

		cout << "4.왼 6.오 8.위 2.아" << endl;
		cin >> iInput;

		int curPosX = m_pPlayer->GetXPos();
		int curPosY = m_pPlayer->GetYPos();
		bool bResult = 0;

		switch (iInput)
		{
		case 4:
			if (curPosX > 0)
			{
				bResult = OnMovement(curPosX - 1, curPosY);
				if (bResult)
					return;
			}
			break;
		case 6:
			if (curPosX < iMapXLen - 1)
			{
				bResult = OnMovement(curPosX + 1, curPosY);
				if (bResult)
					return;
			}
			break;
		case 8:
			if (curPosY > 0)
			{
				bResult = OnMovement(curPosX, curPosY - 1);
				if (bResult)
					return;
			}
			break;
		case 2:
			if (curPosY < iMapYLen -1)
			{
				bResult = OnMovement(curPosX, curPosY + 1);
				if (bResult)
					return;
			}
			break;
		default:
			cout << "잘못된 입력" << endl;
			system("pause");
			break;
		}
	}
}

bool CField::OnMovement(int targetPosX, int targetPosY) // return 0: 넘어가기 목적, return 1: 상위함수 종료 목적
{
	int curPosX = m_pPlayer->GetXPos();
	int curPosY = m_pPlayer->GetYPos();

	// 포탈, 몬스터 아닐 시 이동.
	if (m_Map[targetPosY][targetPosX] == nullptr)
	{
		swap(m_Map[curPosY][curPosX], m_Map[targetPosY][targetPosX]);
		m_pPlayer->MovePos(targetPosX, targetPosY);
		return 0;
	}

	// 포탈인 경우
	else if (m_Map[targetPosY][targetPosX]->GetType() == ET_PORTAL)
	{
		bool bloop = 1;
		while (bloop)
		{
			cout << "마을? (1.예 2.아니오) : ";
			int iInput;
			cin >> iInput;
			switch (iInput)
			{
			case 1:
				Release(); // 필드 해제 후 마을로
				return 1;

			case 2:
				return 0;
			default:
				cout << "잘못된 입력" << endl;
				system("pause");
				break;
			}
		}
	}

	// 몬스터인 경우
	else if (m_Map[targetPosY][targetPosX]->GetType() == ET_MONSTER)
	{
		bool bloop = 1;
		while (bloop)
		{
			cout << "전투? (1.예 2.아니오) : ";
			int iInput;
			cin >> iInput;

			int fightResult;
			switch (iInput)
			{
			case 1:
				fightResult = Fight(m_Map[targetPosY][targetPosX]); // 전투
				if (fightResult == FR_RUN) // 도망 시
				{
					return 0;
				}
				else if (fightResult == FR_WIN) // 몬스터 처치 시
				{
					SAFE_DELETE(m_Map[targetPosY][targetPosX]); // 몬스터 데이터 해제
				}
				else if (fightResult == FR_LOSE) // 사망 시 마을로 보내기
				{
					// 회복은 전투 이후? 혹은 여기?
					Release();
					return 1;
				}
				bloop = 0;
				break;
			case 2:
				bloop = 0;
				break;
			default:
				cout << "잘못된 입력" << endl;
				system("pause");
				break;
			}
		}
	}
}

void CField::Release()
{
	for (int i = 0; i < iMapYLen; ++i)
	{
		for (int j = 0; j < iMapXLen; ++j)
		{
			if (m_Map[i][j] && m_Map[i][j]->GetType() != ET_PLAYER)
				SAFE_DELETE(m_Map[i][j]);
		}
	}
}

void CField::Render()
{
	for (int i = 0; i < iMapXLen + 2; ++i)
		cout << 'w';

	for (int i = 0; i < iMapYLen; ++i)
	{
		cout << endl << 'w';
		for (int j = 0; j < iMapXLen; ++j)
		{
			if (m_Map[i][j] == nullptr)
				cout << ' ';
			else if (m_Map[i][j]->GetType() == ET_PLAYER)
				cout << 'i';
			else if (m_Map[i][j]->GetType() == ET_PORTAL)
				cout << 'p';
			else if (m_Map[i][j]->GetType() == ET_MONSTER)
				cout << 'm';
		}
		cout << 'w';
	}
	cout << endl;
	for (int i = 0; i < iMapXLen + 2; ++i)
		cout << 'w';
}

// 전투:
// 도망 시 0 반환
// 처치 시 1 반환
// 사망 시 2 반환
int CField::Fight(CEntity* pEntity)
{
	// fight 설계에 맞춰 pMonster와 pPlayer 캐스팅 했습니다.
	CMonster* pMonster = dynamic_cast<CMonster*>(pEntity);
	CPlayer* pPlayer = dynamic_cast<CPlayer*>(m_pPlayer);


	cout << "앗! 야생의 " << pMonster->GetName() << "을(를) 발견했다!" << endl;
	system("pause");

	int iInput;

	while (true)
	{
		// 플레이어 턴
		system("cls");
		pPlayer->PrintInfo();
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
				pMonster->OnAttacked(pPlayer);

				if (pMonster->IsDead())
				{
					system("cls");
					pPlayer->PrintInfo();
					pMonster->PrintInfo();
					cout << pMonster->GetName() << "을(를) 해치웠습니다!" << endl;
					system("pause");
					system("cls");
					//SAFE_DELETE(pMonster);
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
				if (pPlayer->SelectPotion())
					bTurnFinished = true;
				break;
			}

			if (bTurnFinished) break;
		}


		system("pause");

		// 몬스터 턴
		system("cls");
		pPlayer->PrintInfo();
		pMonster->PrintInfo();
		cout << "적의 턴입니다." << endl;
		system("pause");
		pPlayer->OnAttacked(pMonster);
		system("pause");
		if (pPlayer->IsDead())
		{
			system("cls");
			pPlayer->PrintInfo();
			pMonster->PrintInfo();
			cout << pMonster->GetName() << "의 일격에 당신은 죽고 말았습니다.." << endl;
			system("pause");
			system("cls");
			pPlayer->SetHpToMax();
			return FR_LOSE;
		}
	}

	return 0;
}
