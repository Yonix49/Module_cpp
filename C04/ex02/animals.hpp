#ifndef DEF_ANIMAL
#define DEF_ANIMAL
#include <cstring>
#include <iostream>
#include <string>

class AAnimal
{
public:
	AAnimal();
	virtual ~AAnimal();
	    
	AAnimal(const AAnimal &src);
	AAnimal(std::string type);
	AAnimal& operator=(const AAnimal &other);
	virtual void makeSound() const = 0; // fonction virtu pure
	virtual std::string getType() const;


	protected:
	std::string type;
};



#endif