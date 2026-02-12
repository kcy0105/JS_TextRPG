#include "pch.h"
#include "CInventory.h"
#include "CPlayer.h"
#include "CItem.h"
#include "CWeapon.h"
#include "CArmor.h"

void CInventory::Initialize()
{
}

void CInventory::Update()
{
    int iInput = 0;

    while (true) {
        system("cls");

        cout << "================= 인벤토리 =================" << endl;

        cout << "1. 무기 인벤토리 2. 방어구 인벤토리 3. 포션 인벤토리 4. 전단계 : ";  // 포션탭에선 장착이 없어지게
        cin >> iInput;

        switch (iInput - 1)
        {
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
}

void CInventory::Release()
{
}

void CInventory::Render(int ItemType)
{
    int iInput = 0;
    int iCursorPos = 0;
    int iCount = m_pPlayer->GetItemCount(ItemType);
    CItem* pItem = NULL;

    while (true) {

        system("cls");

        switch (ItemType) {
        case IT_WEAPON:
            cout << "================= 무기 인벤토리 =================" << endl;
            break;
        case IT_ARMOR:
            cout << "================= 방어구 인벤토리 =================" << endl;
            break;
        case IT_POTION:
            cout << "================= 포션 인벤토리 =================" << endl;
            break;
        }

        if (iCount == 0)
        {
            cout << "비어 있음" << endl;
        }
        else
        {
            for (int i = 0; i < iCount; ++i)
            {
                pItem = m_pPlayer->GetItem(ItemType, i);

                if (pItem)
                {
                    cout << i + 1 << ". " << pItem->GetName();
                    if (i == iCursorPos) {
                        cout << "\t●";
                    }
                    cout << endl;
                }
            }
        }

        cout << "--------------------------------------------" << endl;

        cout << "1. 장착, 3. 장착해제 2. 커서 내리기, 8 : 커서 올리기, 0. 전 단계 : ";
        cin >> iInput;


        /*CWeapon* pWeapon = static_cast<CWeapon*>(pItem);
        CArmor* pArmor = static_cast<CArmor*>(pItem);*/

        CEquipment* pEquip = nullptr;

        if (iCount != 0) {
            pItem = m_pPlayer->GetItem(ItemType, iCursorPos);

            if (ItemType != IT_POTION) {
                pEquip = static_cast<CEquipment*>(pItem);
            }
        }

        switch (iInput) {
        case 1:
            pEquip->Equip(m_pPlayer);
            break;

            if (iCount != 0)
            {
        case 2:
            if (iCursorPos < iCount - 1) {
                ++iCursorPos;
            }
            break;
        case 3:
            pEquip->Unequip(m_pPlayer);
            break;
        case 8:
            if (iCursorPos > 0) {
                --iCursorPos;
            }
            break;
            }

        case 0:
            return;
        default:
            break;
        }
    }
}