/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:45:03 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/22 15:42:18 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat {

	public:

		class GradeTooHighException : std::exception {
			
			public:
				
				virtual const char *what() const throw();
		};

		class GradeTooLowException : std::exception {
			
			public:
				
				virtual const char *what() const throw() {
					return ("Ops, grade is too low!");
				}
		};

		Bureaucrat(void);
		Bureaucrat(std::string const &name, int const grade);
		Bureaucrat(Bureaucrat const *rhs);
		~Bureaucrat(void);

		Bureaucrat&	operator=(Bureaucrat const &rhs);

		std::string const &	getName(void) const;
		int	const			getGrade(void) const;

		void				incrementGrade(int const increment);
		void				decrementGrade(int const decrement);

	private:

		std::string const	name;
		int					grade;
};

std::ostream&	operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
