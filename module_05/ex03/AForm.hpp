/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:50:00 by pedro             #+#    #+#             */
/*   Updated: 2023/03/27 12:02:15 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# ifndef DEBUG
#  define DEBUG 0
#  endif

typedef class Bureaucrat	Bureaucrat;

class AForm {
	
	public:

		class GradeTooHighException : public std::exception {

			public:

				const char  *what() const throw();
		};

		class GradeTooLowException : public std::exception {

			public:

				const char  *what() const throw();
		};
		
		class FormNotSignedException : public std::exception {
			
			public:
			
				const char	*what() const throw();
		};

		class FormNotExistException : public std::exception {
			
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
