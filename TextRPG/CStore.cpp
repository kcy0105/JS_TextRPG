#include "CStore.h"
#include "CPlayer.h"
#include "CNormalHpPotion.h"
#include "CMaxHpPotion.h"
#include "CWeapon.h"
#include "CArmor.h"

void CStore::Initialize()
{
	vecItemList[IT_WEAPON].push_back({EQUIP_NORMAL_SUFFIX + BASIC_WEAPON_NAME, NORMAL_ITEM_PRICE});
	vecItemList[IT_WEAPON].push_back({ EQUIP_RARE_SUFFIX + BASIC_WEAPON_NAME, RARE_ITEM_PRICE });
	vecItemList[IT_WEAPON].push_back({ EQUIP_EPIC_SUFFIX + BASIC_WEAPON_NAME, EPIC_ITEM_PRICE });

	vecItemList[IT_ARMOR].push_back({ EQUIP_NORMAL_SUFFIX + BASIC_ARMOR_NAME, NORMAL_ITEM_PRICE });
	vecItemList[IT_ARMOR].push_back({ EQUIP_RARE_SUFFIX + BASIC_ARMOR_NAME, RARE_ITEM_PRICE });
	vecItemList[IT_ARMOR].push_back({ EQUIP_EPIC_SUFFIX + BASIC_ARMOR_NAME, EPIC_ITEM_PRICE });

	vecItemList[IT_POTION].push_back({ NORMAL_HP_POTION_NAME, NORMAL_POTION_PRICE });
	vecItemList[IT_POTION].push_back({ MAX_HP_POTION_NAME, MAXHP_POTION_PRICE });
}

void CStore::Update()
{
	int iInput = 0;

	while (true) {

		system("cls");

		cout << "---------------[상점]---------------" << endl;
		cout << "1. 무기, 2. 방어구, 3. 포션, 4. 나가기 : ";
		cin >> iInput;

		switch (iInput - 1) {
		case IT_WEAPON:
			Render(IT_WEAPON);
			break;
		case IT_ARMOR:
			Render(IT_ARMOR);
			break;
		case IT_POTION:
			Render(IT_POTION);
			break;
		case IT_COUNT:
			return;
		default:
			break;
		}

	}

	//// TEST
	//m_pPlayer->AddItem(new CNormalHpPotion);
	//m_pPlayer->AddItem(new CMaxHpPotion);
}

void CStore::Release()
{

}

void CStore::Render(int ItemType)
{
	CItem* item;
	int iInput = 0;

	while (true) {

		system("cls");

		switch (ItemType) {
		case IT_WEAPON:
			cout << "---------------[무기상점]---------------" << endl;
			break;
		case IT_ARMOR:
			cout << "---------------[방어구상점]---------------" << endl;
			break;
		case IT_POTION:
			cout << "---------------[포션상점]---------------" << endl;
			break;
		default:
			break;
		}

		for (vector<ItemInfo>::iterator iter = vecItemList[ItemType].begin(); iter != vecItemList[ItemType].end(); ++iter) {
			cout << (*iter).szName << " " << (*iter).iPrice << "원" << endl;
		}

		cout << "소지금 : " << m_pPlayer->GetMoney() << endl;

		cout << "---------------------------------------" << endl;
		cout << "구매 하실 아이템을 선택하세요(0. 나가기) : ";
		cin >> iInput;

		if (iInput == 0) { return; }
		else if (iInput > 0 && iInput - 1 < vecItemList[ItemType].size()) {
			if (m_pPlayer->GetMoney() >= vecItemList[ItemType][iInput-1].iPrice) {
				switch (ItemType) {
				case IT_WEAPON:
					m_pPlayer->AddItem(new CWeapon(iInput - 1));
					break;
				case IT_ARMOR:
					m_pPlayer->AddItem(new CArmor(iInput - 1));
					break;
				case IT_POTION:
					if (iInput == 1) {
						m_pPlayer->AddItem(new CNormalHpPotion());
					}
					else if (iInput == 2) {
						m_pPlayer->AddItem(new CMaxHpPotion());
					}
					break;
				default:
					break;
				}

				m_pPlayer->SetMoney(vecItemList[ItemType][iInput-1].iPrice);

				cout << "구매 완료!" << endl;
			}
			else {
				cout << "잔액 부족." << endl;
			}
		}
		else {
			cout << "입력 오류!" << endl;
		}

		system("pause");
	}
}