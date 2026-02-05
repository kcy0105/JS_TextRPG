#pragma once
#include <string>
using namespace std;

#pragma region MACRO

#define SAFE_DELETE(p) if (p) { delete p; p=nullptr; }

#pragma endregion

#pragma region ENUM

enum ITEM_TYPE
{
	IT_WEAPON = 0,
	IT_ARMOR,
	IT_POTION,
	IT_COUNT
};

enum EQUIP_RARITY
{
	ER_NORMAL,
	ER_RARE,
	ER_EPIC,
	ER_COUNT	// 추가
};


enum POTION_TYPE
{
	PT_NORMAL_HP,
	PT_MAX_HP,
	PT_COUNT	// 추가
};

enum ENTITY_TYPE
{
	ET_PLAYER,
	ET_PORTAL,
	ET_MONSTER,
};

enum MONSTER_TYPE
{
	MT_EASY,
	MT_NORMAL,
};

enum FIGHT_RESULT
{
	FR_RUN,
	FR_WIN,
	FR_LOSE,
};

#pragma endregion

#pragma region CONST
const int ITEM_MAX_COUNT = 16;

const string BASIC_WEAPON_NAME = "검";
const string BASIC_ARMOR_NAME = "갑옷";

const string EQUIP_NORMAL_SUFFIX = "[노말]";	// 평범 -> 노말
const string EQUIP_RARE_SUFFIX = "[레어]";		// 희귀 -> 레어
const string EQUIP_EPIC_SUFFIX = "[에픽]";

// 등급별 아이템 가격 작성
const int NORMAL_ITEM_PRICE = 1000;
const int RARE_ITEM_PRICE = 2000;
const int EPIC_ITEM_PRICE = 3000;

// 포션 가격은 따로 작성
const int NORMAL_POTION_PRICE = 500;
const int MAXHP_POTION_PRICE = 1000;

const string EASY_MONSTER_NAME = "초급 몬스터";
const int EASY_MONSTER_HP = 30;
const int EASY_MONSTER_ATK = 7;

const string NORMAL_MONSTER_NAME = "중급 몬스터";
const int NORMAL_MONSTER_HP = 50;
const int NORMAL_MONSTER_ATK = 10;

const string NORMAL_HP_POTION_NAME = "평범한 체력 포션";
const string MAX_HP_POTION_NAME = "특별한 체력 포션";

const int NORMAL_HP_POTION_INCREMENT = 30;

const int PLAYER_INITIAL_MAX_HP = 100;
const int PLAYER_INITIAL_ATK = 10;

const int WEAPON_NORMAL_ATK_INCREMENT = 5;
const int WEAPON_RARE_ATK_INCREMENT = 7;
const int WEAPON_EPIC_ATK_INCREMENT = 10;

const int ARMOR_NORMAL_MAX_HP_INCREMENT = 5;
const int ARMOR_RARE_MAX_HP_INCREMENT = 7;
const int ARMOR_EPIC_MAX_HP_INCREMENT = 10;
#pragma endregion




