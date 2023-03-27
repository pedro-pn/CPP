/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:45:03 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/27 12:02:25 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

typedef class AForm	AForm;

class Bureaucrat {

	public:

		class GradeTooHighException : public std::exception {
			
			public:
			
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			
			public:
				
				virtual const char *what() const throw();
		};

		Bureaucrat(void);
		Bureaucrat(std::string const &name, int const grade);
		Bureaucrat(Bureaucrat const &rhs);
		~Bureaucrat(void);

		Bureaucrat&	operator=(Bureaucrat const &rhs);

		std::string const &	getName(void) const;
		int					getGrade(void) const;

		void				incrementGrade(int const increment);
		void				decrementGrade(int const decrement);

		void				signForm(AForm &form);
		void				executeForm(AForm const &form) const;

	private:

		std::string const	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
