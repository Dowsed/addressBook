#ifndef _PHONEBOOK_H_
#define _PHONEBOOK_H_

#include <string>
#include <list>
#include <fstream>
#include "contact.h"

class PhoneBook
{
//friend class Contact;
public:
	PhoneBook();
	~PhoneBook();
	//methods
	bool addContact();
	bool deleteContact();
	bool searchContacts();
	bool printContacts();
	bool readContact(std::string first, std::string last, std::string phone, int d, int m, int y);
	bool readFromFile();
	bool writeToFile();
	bool compareLastName();
	//attributes
	static int ID;
private:
	//attributes
	std::list<Contact> phoneBook;
	int idNum;
	//methods
	void simplePrint();
	void alphabeticalPrint();
	void birthdayPrint();
	void idDelete(int id);
};
#endif // _PHONEBOOK_H_
