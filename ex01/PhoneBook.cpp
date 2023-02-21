#include "PhoneBook.hpp"
#include <iomanip>
#include <stdlib.h>

PhoneBook::PhoneBook(void) : number_of_contacts(0)
{
	std::cout << "Welcome to my scrappy book!" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Scrappy book has been deleted FOREVER!" << std::endl;
}

void	PhoneBook::addContact(int index)
{
	this->contacts[index % 8].setFirstName();
	this->contacts[index % 8].setLastName();
	this->contacts[index % 8].setNickname();
	this->contacts[index % 8].setPhoneNumber();
	this->contacts[index % 8].setDarkestSecret();
	this->contacts[index % 8].setContactIndex(index % 8);
	if (this->number_of_contacts < 8)
		this->number_of_contacts++;
}

void	PhoneBook::printResume(void)
{
	std::cout << std::endl;
	this->printSummary();
	for (int i = 0; i < this->number_of_contacts; i++){
		this->contacts[i].printResume();
	}
	std::cout << std::endl;
}

void	PhoneBook::printFull(void)
{
	std::string		index_str;
	int				index;

	while (1){
		std::cout << "Insert an index: ";
		std::cin >> index_str;
		index = atoi(index_str.c_str());
		if (index > 0 && index <= this->number_of_contacts)
			break ;
		std::cout << "Insert a valid index!" << std::endl;
	}
	std::cout << std::endl;
	this->contacts[index - 1].printFull();
}

void	PhoneBook::searchContact(void)
{
	if (this->number_of_contacts == 0)
	{
		std::cout << "Scrappy book is empty!" << std::endl;
		return ;
	}
	this->printResume();
	this->printFull();
}

void	PhoneBook::printSummary(void)
{
	std::cout << std::setw(10);
	std::cout << "index" << "|";
	std::cout << std::setw(10);
	std::cout << "first name" << "|";
	std::cout << std::setw(10);
	std::cout << "last name" << "|";
	std::cout << std::setw(10);
	std::cout << "nickname" << "|" << std::endl;
}
