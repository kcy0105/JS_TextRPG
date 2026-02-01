#pragma once
class CEntity
{
private:
	int m_iEntityType;
	int m_iPosX;
	int m_iPosY;

public:
	CEntity(int iEntityType) : m_iEntityType(iEntityType), m_iPosX(0), m_iPosY(0)
	{
	}
};

