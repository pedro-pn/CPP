#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : number_of_contacts(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::addContact(int index)
{
	this->contacts[index % 8].setFirstName();
	this->contacts[index % 8].setLastName();
	this->contacts[index % 8].setNickname();
	this->contacts[index % 8].setPhoneNumber();
	this->contacts[index % 8].setDarkestSecret();
	this->number_of_contacts++;
	this->contacts[index & 8].setContactIndex(index % 8);
}

void	PhoneBook::searchContact(void)
{
	int			index;

	this->printSummary();
	for (int i = 0; i < this->number_of_contacts; i++){
		this->contacts[i].printResume();
	}
	while (1){
		std::cout << "Insert and index " << std::endl;
		std::cin >> index;
		std::cout << "number inputed: " << index << std::endl;
	}
}

void	PhoneBook::printSummary(void)
{
	std::cout << std::setw(11);
	std::cout << "index|";
	std::cout << std::setw(11);
	std::cout << "first name|";
	std::cout << std::setw(11);
	std::cout << "last name|";
	std::cout << std::setw(11);
	std::cout << "nickname" << std::endl;
}
