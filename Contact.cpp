#include "Contact.h"
#include <iostream>

int Contact::ID = 0;

Contact::Contact()
	: firstName{""}, lastName{""}, phoneNum{""}, date{00}, month{00}, year{0000}
{
	idNum = ++ID;
}

Contact::Contact(std::string first, std::string last, std::string phone, int d, int m, int y)
	: firstName{first}, lastName{last}, phoneNum{phone}, date{d}, month{m}, year{y} 
{
	idNum = ++ID;
}

Contact::~Contact()
{
}

bool Contact::setName(std::string first, std::string last)
{
	firstName = first;
	lastName = last;
	return true;	
}

bool Contact::setPhone(std::string phone)
{
	phoneNum = phone;
	return true;
}

bool Contact::setDateOfBirth(int d, int m, int y)
{
	date = d;
	month = m;
	year = y;
	return true;
}

std::string Contact::getFullName()
{	
	std::string fullName = firstName + " " + lastName;
	return fullName;
}

std::string Contact::getFirstName()
{
	return firstName;
}

std::string Contact::getLastName()
{	
	return lastName;
}

std::string Contact::getPhone()
{
	return phoneNum;
}
int Contact::getDate()
{
	return date;
}
int Contact::getMonth()
{
	return month;
}
int Contact::getYear()
{
	return year;
}

int Contact::getID()
{
	return idNum;
}

bool Contact::printName()
{
	std::cout << "Full name is: " << firstName << " " << lastName << std::endl;
	return 1;
}

bool Contact::printPhone()
{
	std::cout << "Phone number is: " << phoneNum << std::endl;
	return true;
}

bool Contact::printDateOfBirth()
{
	std::cout << "Date of birth is: " << date << "/" << month << "/" << year << std::endl;
	return true;
}

bool Contact::printID()
{
	std::cout << "ID Number: " << idNum << std::endl;
	return 1;
}