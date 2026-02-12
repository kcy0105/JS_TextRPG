#pragma once

class CItem
{
protected:
	int m_iPrice;
	string m_szName;

private:
	int m_iItemType;


public:
	CItem(int iItemType) : m_iItemType(iItemType), m_iPrice(0), m_szName{}
	{

	}

public:
	int GetItemType() const { return m_iItemType; }
	string GetName() const { return m_szName; }
	int GetPrice() const { return m_iPrice; }
};

