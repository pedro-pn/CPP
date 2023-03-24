/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:40:20 by pedro             #+#    #+#             */
/*   Updated: 2023/03/23 19:36:29 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# define TREE "               ,@@@@@@@,\n       ,,,.   ,@@@@@@/@@,  .oo8888o.\n    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n   `&%\\ ` /%&'    |.|        \\ '|8'\n       |o|        | |         | |\n       |.|        | |         | |\n    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_"

class ShrubberyCreationForm : public AForm {
	
	public:
	
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
		~ShrubberyCreationForm(void);	

		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const &rhs);

		void	beExecuted(void) const;
				
	private:
	
		std::string	_target;

};

#endif
