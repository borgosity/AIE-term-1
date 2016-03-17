#pragma once
class Player
{
public:
	Player();
	Player(int location, char * name);
	virtual ~Player();
	int GetLocation();
	const char* GetName();
	int GetStrength();
	int GetHealth();
	int Getluck();
	void SetLocation(int location);
protected:
	int m_location;
	const char * m_name;
	int m_strength;
	int m_health;
	int m_luck;
private:
	void deleteString(const char * string);
};

