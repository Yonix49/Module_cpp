#ifndef DEF_HUMANA
#define DEF_HUMANA
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack();
	// tjr passer par la reference c'est beaucoup mieux
    
private:
    std::string name;
    Weapon& weapon;
};


#endif