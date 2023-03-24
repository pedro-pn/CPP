/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:41:07 by pedro             #+#    #+#             */
/*   Updated: 2023/03/24 18:26:42 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
	
	public:
	
		Intern(void);
		Intern(Intern const &rhs);
		~Intern(void);
		
		Intern&	operator=(Intern const &rhs);
		
		AForm	*makeForm(std::string const &form, std::string const &target);
		AForm	*createForm(std::string const &form, std::string const &target);
		
		
	private:
	
		AForm	*_makeShruberryCreationForm(std::string const &target);
		AForm	*_makeRobotomyRequestForm(std::string const &target);
		AForm	*_makePresidentialParonForm(std::string const &target);

};

#endif
