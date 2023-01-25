#include "P_info.h"

std::ostream& operator<<(std::ostream& os, const P_info& data)
{
	os << data.name  << std::endl;
	os << data.surname  << std::endl;
	os << data.age << std::endl;
	os << data.height<< std::endl;
	os << data.weight;

	return os;
}

std::istream& operator>>(std::istream& is,  P_info& dt)
{
	std::string name = (std::string)dt.name;
	std::string surname = (std::string)dt.surname;

	is >> name;
	is >> surname;
	is >> dt.age;
	is >> dt.height;
	is >> dt.weight;
	return is;
}


void P_info::print()
{
	std::cout << "name: " << name << std::endl;
	std::cout << "surname: " << surname << std::endl;
	std::cout << "age: " << age << " years old" << std::endl;
	std::cout << "height: " << height << " cm" << std::endl;
	std::cout << "weight: " << weight << " kg" << std::endl;
}

bool P_info::operator<(const P_info& obj)
{
	if (this->age < obj.age)
	{
		return true;
	}
	else
	{
		return false;
	}	
}
bool P_info::operator>(const P_info& obj)
{
	if (this->age > obj.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool P_info::operator<=(const P_info& obj)
{
	if (this->age <= obj.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool P_info::operator>=(const P_info& obj)
{
	if (this->age >= obj.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool P_info::operator==(const P_info& obj)
{
	if (this->name    == obj.name    &&
		this->surname == obj.surname &&
		this->age     == obj.age     &&
		this->weight  == obj.weight  &&
		this->height  == obj.height    )
	{
		return true;
	}
	else
	{
		return false;
	}
}
