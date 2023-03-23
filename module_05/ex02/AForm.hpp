/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:50:00 by pedro             #+#    #+#             */
/*   Updated: 2023/03/23 19:37:06 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

typedef class Bureaucrat	Bureaucrat;

class AForm {
	
	public:

		class GradeTooHighException : std::exception {

			public:

				const char  *what() const throw();
		};

		class GradeTooLowException : std::exception {

			public:

				const char  *what() const throw();
		};
		
		class FormNotSignedException : std::exception {
			
			public:
			
				const char	*what() const throw();
		};

		AForm(void);
		AForm(std::string const &name, int const gradeToSign, int const gradeToExecute);
		AForm(AForm const &rhs);
		virtual	~AForm(void);

		AForm&	operator=(AForm const &rhs);

		std::string const	&getName(void) const;
		bool				getSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		void				beSigned(Bureaucrat const &bureaucrat);
		void				execute(Bureaucrat const &executor) const;
		virtual void		beExecuted(void) const = 0;

	private:

		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		
};

std::ostream&	operator<<(std::ostream &o, AForm const &rhs);

#endif
