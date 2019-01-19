// Phone Book
// main.cpp
// copyright © 2018 Peter Dowsett

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <chrono>
#include <thread>
#include "Contact.h"
#include "PhoneBook.h"

//function prototypes for menu
bool readFile(PhoneBook *phoneBookPtr);
void displayMenu();
char getSelection();
bool quitApplication(PhoneBook *phoneBookPtr);
void sleep();

int main()
{
	//pointer to phonebook object
	PhoneBook *phoneBookPtr;
	//initialise phone book dynamically and set it to pointer
	phoneBookPtr = new PhoneBook;
	//fills PhoneBook object will data from file
	phoneBookPtr->readFromFile();
	char selection {}; // selection variable for menu choices
	bool quit {false};
	do {
		displayMenu();
		selection = getSelection();
		//selection if else-if ladder
		if (selection == '1'){
			phoneBookPtr->addContact();
		}
		else if (selection == '2'){
			phoneBookPtr->deleteContact();
		}
		else if (selection == '3'){
			phoneBookPtr->searchContacts();
			sleep();
		}
		else if (selection == '4'){
			phoneBookPtr->printContacts();
			sleep();
		}
		else if (selection == '5'){
			quit = quitApplication(phoneBookPtr);
		}
		else {
			std::cout << "invalid selection, please try again" << std::endl;
		}
	} while (quit != true);
std::cout << std::endl;
return 0;
}

void displayMenu(){
	std::cout << "\n\n####################################################################################" << std::endl;
	std::cout << "############################# Pete's Address Book v1.0 #############################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "# 1 - Add Contact                                                                  #" << std::endl;
	std::cout << "# 2 - Delete Contact                                                               #" << std::endl;
	std::cout << "# 3 - Search Contacts                                                              #" << std::endl;
	std::cout << "# 4 - Print Contacts                                                               #" << std::endl;
	std::cout << "# 5 - Quit                                                                         #" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
}

char getSelection(){
	char selection{};
	std::cout << "Please make a selection: " << std::endl;
	std::cin >> selection;
	return selection;
}

bool quitApplication(PhoneBook *phoneBookPtr){
	std::cout << "Are you sure you want to quit? y/n" << std::endl;
	char selection;
	bool quit {false};
	std::cin >> selection;
	selection = toupper(selection);
	if (selection == 'Y'){
		phoneBookPtr->writeToFile();
		std::cout << "Goodbye" << std::endl;
		quit = true;
	}
	else if (selection == 'N'){
		std::cout << "Quit cancelled" << std::endl;
	}
	else {
		std::cout << "Not a valid selection, resuming application" << std::endl;
	} 
	return quit;
}

void sleep(){
	//console sleeps for 2 seconds before menu re-appears
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}