#pragma once



// The base class from which all guns derive
class Gun
{
public:
	Gun();
	~Gun();

    void fire();

    float damage() const;

private:
    float m_damage;
};

