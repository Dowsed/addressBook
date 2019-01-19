#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <string>

class Contact
{
public:
	Contact();
	Contact(std::string first, std::string last, std::string phone, int d, int m, int y);
	
	~Contact();
	//methods
	bool setName(std::string first, std::string last);
	bool setPhone(std::string phone);
	bool setDateOfBirth(int d, int m, int y);
	std::string getFullName();
	std::string getFirstName();
	std::string getLastName();
	std::string getPhone();
	int getDate();
	int getMonth();
	int getYear();
	int getID();
	bool printName();
	bool printPhone();
	bool printDateOfBirth();
	bool printID();
	
private:
	//attributes
	int idNum;
	static int ID;
	std::string firstName;
	std::string lastName;
	std::string phoneNum;
	int date;
	int month;
	int year;

	
	
};

#endif // _CONTACT_H_
