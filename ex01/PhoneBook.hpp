#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

	public:

		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(int index);
		void	searchContact(void);
		void	printSummary(void);
	
	private:

		Contact contacts[8];
		int		number_of_contacts;
		void	printResume(void);
		void	printFull(void);
};

#endif
