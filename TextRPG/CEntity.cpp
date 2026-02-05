#include "CEntity.h"

void CEntity::MovePos(int newXPos, int newYPos)
{
	m_iPosX = newXPos;
	m_iPosY = newYPos;
}

void CEntity::ChangeType(int iEntityType)
{
	m_iEntityType = iEntityType;
}