#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::setFirstName(void)
{
	std::string	first_name;

	std::cin.ignore();
	while (1){
		std::cout << "Insert first name: ";
		std::getline(std::cin, first_name);
		if (first_name.size() != 0)
			break ;
	}
	this->firstName = first_name;
}

void	Contact::setLastName(void)
{
	std::string	last_name;

	while (1){
		std::cout << "Insert last name: ";
		std::getline(std::cin, last_name);
		if (last_name.size() == 0)
			continue ;
		this->lastName = last_name;
		break ;
	}
}

void	Contact::setNickname(void)
{
	std::string	nickname;

	while (1){
		std::cout << "Insert nickname: ";
		std::getline(std::cin, nickname);
		if (nickname.size() == 0)
			continue ;
		this->nickname = nickname;
		break ;
	}
}

bool	Contact::checkPhoneNumber(void)
{
	for (size_t i = 0; i < this->phoneNumber.size(); i++){
		if (std::isdigit(this->phoneNumber[i]) == 0){
			return (false);
		}
	}
	return (true);
}

void	Contact::setPhoneNumber(void)
{
	std::string	phone_number;

	while (1){
		std::cout << "Insert a phone number: ";
		std::getline(std::cin, phone_number);
		this->phoneNumber = phone_number;
		if (phone_number.size() == 0)
			continue ;
		else if (this->checkPhoneNumber() == false)
		{
			std::cout << "Invalid phone number!" << std::endl;
			continue ;
		}
		break ;

	}
}

void	Contact::setDarkestSecret(void)
{
	std::string	darkest_secret;

	while (1){
		std::cout << "Insert contact's darkest secret: ";
		std::getline(std::cin, darkest_secret);
		if (darkest_secret.size() == 0)
			continue ;
		this->darkestSecret = darkest_secret;
		break ;
	}
}

void	Contact::setContactIndex(int index)
{
	this->index = index;
}

void	Contact::formatContactOutput(std::string info)
{
	if (info.size() > 10)
	{
		info.resize(9);
		info.resize(10, '.');
	}
	std::cout << std::setw(10);
	std::cout << info << "|";
}

void	Contact::printResume(void)
{
	std::cout << std::setw(10);
	std::cout << this->index + 1 << "|";
	this->formatContactOutput(this->firstName);
	this->formatContactOutput(this->lastName);
	this->formatContactOutput(this->nickname);
	std::cout << std::endl;
}

void	Contact::printFull(void)
{
	std::cout << "ihu!" << std::endl;
}
