#include "PhoneBook.h"
#include <iostream>
#include <iterator>

PhoneBook::PhoneBook()
{
	
}

PhoneBook::~PhoneBook()
{
}

bool PhoneBook::addContact()
{	
	std::string first; std::string last;
	std::cout << "Please enter the contacts first name and surname separated by a space: " << std::endl;
	std::cin >> first >> last;
	
	std::string phone;
	std::cout << "Please enter the contacts phone number: " << std::endl;
	std::cin >> phone;
	
	int d{00}; int m{00}; int y{0000};
	std::cout << "Please enter the contacts date (DD), month (MM) and year (YYYY) of birth separated by spaces: " << std::endl;
	std::cin >> d >> m >> y;
	
	Contact contact(first, last, phone, d, m, y);
	phoneBook.push_back(contact);
	
	return true;
}
bool PhoneBook::deleteContact()
{	
	std::cout << "===============================================" << std::endl;
	std::cout << "Please choose an option" << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "A - Remove a single entry" << std::endl;
	std::cout << "B - Clear entire phone book" << std::endl;
	char option;
	std::cin >> option;
	option = toupper(option);
	if (option == 'A'){
		std::cout << "===============================================" << std::endl;
		simplePrint();
		std::cout << "Please type the ID of the contact to delete" << std::endl;
		int idRemove;
		std::cin >> idRemove;
		idDelete(idRemove);
	}
	else if (option == 'B')
	{
		char option2;
		std::cout << "Are you sure you want to clear the entire phone book? y/n" << std::endl;
		std::cin >> option2;
		option2 = toupper(option2);
		if (option2 == 'Y'){
			phoneBook.clear();
		}
		else if (option2 == 'N'){
			std::cout << "Returning to main menu" << std::endl;
		}
		else {
			std::cout << "Invalid selection" << std::endl;
		}
	}
	else 
	{
		std::cout << "invalid selection" << std::endl;
	}
	return 1;
}
bool PhoneBook::searchContacts()
{	
	int numResults {0};
	std::string name;
	std::cout << "Please enter a name to search for: " << std::endl;
	//std::getline(std::cin,name);
	std::cin >> name;
	std::cout << "===============================================" << std::endl;
	std::list<Contact>::iterator iter;
	for (iter = phoneBook.begin(); iter != phoneBook.end(); iter++){
		if ((Contact(*iter)).getFullName().find(name) != std::string::npos){
			Contact(*iter).printName();
			Contact(*iter).printPhone();
			numResults++;
			std::cout << "===============================================" << std::endl;
		}
	}
	if (numResults == 0) {
		std::cout << "Name not found" << std::endl;
		std::cout << "===============================================" << std::endl;
	}
	else {
		std::cout << "Number of results: " << numResults << std::endl;
		std::cout << "===============================================" << std::endl;
	}
	return 1;
}
bool PhoneBook::printContacts()
{
	std::cout << "===============================================" << std::endl;
	std::cout << "Please choose an option" << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "A - Print by ID" << std::endl;
	std::cout << "B - Print alphabetically by surname" << std::endl;
	std::cout << "C - Print matching birth dates" << std::endl;
	char option;
	std::cin >> option;
	option = toupper(option);
	if (option == 'A'){
		std::cout << "===============================================" << std::endl;
		simplePrint();
	}
	else if (option == 'B')
	{
		alphabeticalPrint();
	}
		
	else if (option == 'C') 
	{
			birthdayPrint();
	}
	else 
	{
		std::cout << "invalid selection" << std::endl;
	}
	return 1;
}

void PhoneBook::idDelete(int id){
	std::list<Contact>::iterator iter;
	for (iter = phoneBook.begin(); iter != phoneBook.end(); iter++){
		if (id == Contact(*iter).getID()){
			//ID numbers start at 1 and list starts at position 0 so index is id-1
			phoneBook.erase(iter);
			std::cout << "ID No:" << id << ": " << Contact(*iter).getFullName() << " removed successfully." << std::endl;
		}
	}
}

void PhoneBook::simplePrint(){
	std::cout << "===============================================" << std::endl;
	std::list<Contact>::iterator iter;
	for (iter = phoneBook.begin(); iter != phoneBook.end(); ++iter){
		Contact(*iter).printID();
		Contact(*iter).printName();
		Contact(*iter).printPhone();
		Contact(*iter).printDateOfBirth();
		std::cout << "===============================================" << std::endl;
	}
}


void PhoneBook::alphabeticalPrint(){
	compareLastName();
}

bool PhoneBook::compareLastName(){
	std::list<Contact>::iterator iter;
	std::list<Contact>::iterator iter2;
	for (iter = phoneBook.begin(), iter2 = std::next(phoneBook.begin()); iter2 != phoneBook.end(); iter++, iter2++){
		//std::cout << "iter: " << Contact(*iter).getLastName() << std::endl;
		//std::cout << "iter2: " << Contact(*iter2).getLastName() << std::endl;
		if (Contact(*iter).getLastName() < Contact(*iter2).getLastName()){
			std::cout << "0";
		}

		else {
			std::cout << "1";
		}

	}
}

void PhoneBook::birthdayPrint(){
	std::cout << "Printing by birthday" << std::endl;
}

bool PhoneBook::readContact(std::string first, std::string last, std::string phone, int d, int m, int y)
{	
	Contact contact(first, last, phone, d, m, y);
	phoneBook.push_back(contact);
	return true;
}

bool PhoneBook::readFromFile()
{
	std::ifstream inputFile;
	inputFile.open("../phoneBook.txt"); // CodeLite specific please check folder extensions on other IDEs
	if (!inputFile){
		std::cerr << "Problem opening file" << std::endl;
		return 1;
	}
	while (!inputFile.eof()){
		std::string first; std::string last; std::string phone; int d; int m; int y;
		inputFile >> first >> last >> phone >> d >> m >> y;
		readContact(first, last, phone, d, m, y);
	}
	inputFile.close();
	return 0;
}

bool PhoneBook::writeToFile()
{
	std::ofstream outputFile;
	outputFile.open("../phoneBook.txt"); // like inputFile check IDE for correct folder extension
	if (!outputFile){
		std::cerr << "Problem opening file" << std::endl;
		return 1;
	}
	std::list<Contact>::iterator iter;
	std::string first; std::string last; std::string phone; int d{0}; int m{0}; int y{0};
	for (iter = phoneBook.begin(); iter != phoneBook.end(); iter++){
		first = Contact(*iter).getFirstName();
		last = Contact(*iter).getLastName();
		phone = Contact(*iter).getPhone();
		d = Contact(*iter).getDate();
		m = Contact(*iter).getMonth();
		y = Contact(*iter).getYear();
		
		outputFile << " " << first << " " << last << " "<< phone << " " << d << " " << m << " "<< y;
	}
	
	outputFile.close();
	return 0;
}
