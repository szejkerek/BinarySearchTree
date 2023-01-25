#pragma once
#include <iostream>
#include <string>
class P_info {

	const char* name = new char[25];
	const char* surname = new char[25];

	int age;
	double height;
	double weight;

public:
	//Konstruktor
	P_info() : name(""), surname(""), age(0), height(0), weight(0) {}
	//Konstruktor
	P_info(const char* _name, const char* _surname, int _age, double _height, double _weight) :
		name(_name), surname(_surname), age(_age), height(_height), weight(_weight) {}  

	void print();

	//Operatory
	bool operator<(const P_info& obj);
	bool operator>(const P_info& obj);
	bool operator<=(const P_info& obj);
	bool operator>=(const P_info& obj);
	bool operator==(const P_info& obj);

	friend std::ostream& operator<<(std::ostream& os, const P_info& dt);
	friend std::istream& operator>>(std::istream& is,  P_info& dt);
};
