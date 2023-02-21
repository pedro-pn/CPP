#include "PhoneBook.hpp"

 int main(void)
{
	PhoneBook	PhoneBook;
	std::string	input;
	int			contact_index = 0;

	while (1)
	{
		std::cout << "Type ADD, SEARCH or EXIT: ";
		std::cin >> input;
		if (input == "ADD"){
			PhoneBook.addContact(contact_index);
			contact_index++;
		}
		else if (input == "SEARCH")
			PhoneBook.searchContact();
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
