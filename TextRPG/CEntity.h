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


	// 추가 사항
public:
	virtual void	Render() {}
	virtual void Set_Damage(int iAttack) {}

public:
	int GetXPos() const { return m_iPosX; }
	int GetYPos() const { return m_iPosY; }
	void MovePos(int newXPos, int newYPos);
	int GetType() const { return m_iEntityType; }
	void ChangeType(int iEntityType);
};

