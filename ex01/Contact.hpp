#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>

class Contact {

	public:
		
		Contact(void);
		~Contact(void);

		void	setFirstName(void);
		void	setLastName(void);
		void	setNickname(void);
		void	setPhoneNumber(void);
		void	setDarkestSecret(void);
		void	setContactIndex(int index);

		void	printResume(void);


	private:

		int			index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string phoneNumber;
		std::string	darkestSecret;

		bool	checkPhoneNumber(void);
		void	formatContactOutput(std::string info);
};

#endif