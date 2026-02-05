#include "CPlayer.h"
#include "CPotion.h"
#include "pch.h"

void CPlayer::AddHp(int iValue)
{
	m_iHp += iValue;
	if (m_iHp > m_iMaxHp) m_iHp = m_iMaxHp;
}

void CPlayer::SetHpToMax()
{
	m_iHp = m_iMaxHp;
}

bool CPlayer::SelectPotion() // 포션 선택 여부를 반환
{
	int iPotionCount = m_iItemCount[IT_POTION];

	if (iPotionCount == 0)
	{
		cout << "보유한 포션이 없습니다." << endl;
		return false;
	}

	cout << "사용할 포션을 고르십시오." << endl;

	for (int i = 0; i < iPotionCount; i++)
	{
		CPotion* pPotion = static_cast<CPotion*>(m_pItem[IT_POTION][i]);
		cout << i + 1 << ". " << pPotion->GetName() << endl;
	}
	cout << iPotionCount+1 << ". 돌아가기" << endl;

	int iInput;
	while (true)
	{
		cin >> iInput;
		if (iInput >= 1 && iInput <= iPotionCount)
		{
			UsePotion(iInput-1);
			break;
		}
		else if (iInput == iPotionCount + 1)
		{
			return false;
		}
		else
		{
			cout << "잘못된 입력값입니다." << endl;
		}
	}

	return true;
}

void CPlayer::UsePotion(int iIndex)
{
	CPotion* pPotion = static_cast<CPotion*>(m_pItem[IT_POTION][iIndex]);
	pPotion->Use(this);

	SAFE_DELETE(pPotion);

	for (int i = iIndex + 1; i < m_iItemCount[IT_POTION]; i++)
	{
		m_pItem[IT_POTION][i - 1] = m_pItem[IT_POTION][i];
	}
	m_pItem[IT_POTION][m_iItemCount[IT_POTION] - 1] = nullptr;
	m_iItemCount[IT_POTION]--;
}

void CPlayer::AddItem(CItem* pItem)
{
	int iItemType = pItem->GetItemType();
	m_pItem[iItemType][m_iItemCount[iItemType]++] = pItem;
}
