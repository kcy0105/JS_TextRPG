#pragma once
#include "CPotion.h"
#include "Define.h"

class CHpPotion : public CPotion
{
public:
	CHpPotion() : CPotion(PT_HP) { }
};

