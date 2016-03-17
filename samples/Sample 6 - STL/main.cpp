/******************************************************************************

This sample shows just a small part of the STL, e.g. vector and map, and
the basic concept of iterators.

*******************************************************************************/
#include <iostream>



/******************************************************************************
*******************************************************************************/
#include <vector> // Use this header to access std::vector
void testVector()
{
    // A std::vector is a dynamic array of anything (becauser it's a template)
    std::vector<int> myVector;

    // Add some ints to the array
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // ...or we can resize the vector add elements directly
    myVector.resize(3);
    myVector[0] = 10;
    myVector[1] = 20;
    myVector[2] = 30;

    // We can iterate through the vector by indices (exactly as you would for an array)
    for (size_t i = 0; i < myVector.size(); i++)
    {
        std::cout << myVector[i] << "\n";
    }

    // Or we can iterate though the vector by using an STL iterator. This way of 
    // doing it is more generic will work on other types of STL container. Note that
    // the iterator behaves like a pointer, i.e. you increment and de-reference it 
    // like a pointer.INternally, it actually is a pointer.
    for (std::vector<int>::const_iterator it = myVector.begin(); it != myVector.end(); it++)
    {
        std::cout << *it << "\n";
    }
}

/******************************************************************************
*******************************************************************************/
void testVectorWithTypedef()
{
    // To avoid some of the cumbersome syntax, many programmers use typedefs
    // to streamline things. So, repeating the previous example, we end up with:
    typedef std::vector<int> MyVector;

    MyVector myVector;

    myVector.push_back(100);
    myVector.push_back(200);

    for (MyVector::const_iterator it = myVector.begin(); it != myVector.end(); it++)
    {
        std::cout << *it << "\n";
    }
}

/******************************************************************************
*******************************************************************************/
#include <map> // Use this header to access std::map
void testMap()
{
    // A map is an associative container, meaning that it contains items which
    // are each associayed with a key. For this sample, we'll imagine that
    // we a container map of weapons, each with an identifying name, and some
    // information which we'll store for the weapon.

    //First, the struct:
    struct Weapon
    {
        std::string id;
        float range;
        float damage;
    };

    // Now we defne our map. Again, we use a typedef to streamline the definition:
    // We declare the type that we'll be using as the key (in this case, a std::string)
    // and also the type that we'll be associating with the key (in this case, Weapon).
    typedef std::map< std::string, Weapon> WeaponMap;

    // Now we can create our WeaponMap.
    WeaponMap weapons;

    // Insert some weapons into the map

    Weapon knife;
    knife.range = 0.2f;
    knife.damage = 1;
    weapons.insert(WeaponMap::value_type("knife", knife));

    Weapon club;
    club.range = 0.5f;
    club.damage = 0.3f;
    weapons.insert(WeaponMap::value_type("club", club));

    Weapon gun;
    gun.range = 1000;
    gun.damage = 100;
    weapons.insert(WeaponMap::value_type("gun", gun));

    // Note that we didn't perform any error handling withi the above code.
    // The 'insert' will be ignored if the specified key is already in the map.
    // Here is how we test whether the insert actually works. The insert 
    // function returns a std::pair which tells us what happened with the insert.
    std::pair <WeaponMap::iterator, bool> result;
    result = weapons.insert(WeaponMap::value_type("gun", gun));
    if (! result.second)
    {
        std::cout << "A gun already exists in the map!\n";
    }

    // Ierate through every item in the map
    for (WeaponMap::const_iterator it = weapons.begin(); it != weapons.end(); it++)
    {
        std::cout << it->second.range << "  " << it->second.damage << "\n";

        // It we are accessing many items within the weapon, it might be more 
        // convenient (and readable) to first create a reference.
        const Weapon & weapon = it->second;

        std::cout << weapon.range << "  " << weapon.damage << "\n";
    }

    // Find a specific item in the map
    WeaponMap::const_iterator it = weapons.find("gun");
    if (it != weapons.end())
    {
        std::cout << "The gun has damage " << it->second.damage;
    }
    else
    {
        std::cout << "No gun found!\n";
    }
}

/******************************************************************************
*******************************************************************************/
void main()
{
    try
    {
        testVector();
        testVectorWithTypedef();
        testMap();

        std::cout << "\n\nFinished\n\n";
    }
    catch (std::exception & e)
    {
        std::cout << "\n\nException - " << e.what() << "\n\n";
    }
    catch (...)
    {
        std::cout << "\n\nUnhandled exception\n\n";
    }
}