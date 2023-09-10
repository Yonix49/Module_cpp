#ifndef DEF_Animal
#define DEF_Animal
#include <cstring>
#include <iostream>
#include <string>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	    
	Animal(const Animal &src);
	Animal(std::string type);
	Animal& operator=(const Animal &other);
	virtual void makeSound() const;
	virtual std::string getType() const;


	protected:
	std::string type;
};



#endif