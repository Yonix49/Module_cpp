#ifndef DEF_WrongAnimal
#define DEF_WrongAnimal
#include <cstring>
#include <iostream>
#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal(std::string type);
	WrongAnimal& operator=(const WrongAnimal &other);
	virtual void makeSound() const;
	std::string	getType() const;

	protected:
	std::string type;
};



#endif