#include <iostream> 
using namespace std;

class MyClass {
	int x;
public:
	void setX(int i) { x = i; }
	int getX() { return x; }
};

class Zombie
{
public:
	int GetStrength() {	return health;};
	void SetHealth(int i) { health = i; };

private:
	int attackStrength = 0;
	int health = 0;
	//string previousJob = nullptr;
};

int main()
{
	Zombie obs[4];
	int i;

	for (i = 0; i < 4; i++)
		obs[i].SetHealth(i);

	for (i = 0; i < 4; i++)
		cout << "obs[" << i << "].getX(): " << obs[i].GetStrength() << "\n";

	return 0;
}