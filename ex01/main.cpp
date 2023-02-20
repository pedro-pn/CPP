#include "PhoneBook.hpp"

 int main(void)
{
	PhoneBook	PhoneBook;
	std::string	input;
	int			contact_index = 0;
	

	std::cout << "Welcome to my scrappy book!" << std::endl;
	while (1)
	{
		std::cout << "The book is empty! You can ADD, SEARCH or EXIT: " << std::endl;
		std::cin >> input;
		if (input == "ADD"){
			PhoneBook.addContact(contact_index);
			contact_index++;
		}
		else if (input == "SEARCH")
			PhoneBook.searchContact();
		else if (input == "EXIt")
		{
			std::cout << "Closing scrappy book!" << std::endl;
			break ;
		}
	}

	return (0);
}
