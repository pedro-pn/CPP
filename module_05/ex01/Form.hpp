/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:50:00 by pedro             #+#    #+#             */
/*   Updated: 2023/03/22 20:40:48 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

typedef class Bureaucrat Bureaucrat;

class Form {
    
    public:

        class GradeTooHighException : std::exception {

            public:

                const char  *what() const throw();
        };

        class GradeTooLowException : std::exception {

            public:

                const char  *what() const throw();
        };

        Form(void);
        Form(std::string const &name, int const gradeToSign, int const gradeToExecute);
        Form(Form const &rhs);
        ~Form(void);

        Form&   operator=(Form const &rhs);

        std::string const   &getName(void) const;
        bool                getSigned(void) const;
        int                 getGradeToSign(void) const;
        int                 getGradeToExecute(void) const;

        void                beSigned(Bureaucrat const &bureaucrat);

    private:

        std::string const   _name;
        bool                _signed;
        int const           _gradeToSign;
        int const           _gradeToExecute;
        
};

std::ostream&   operator<<(std::ostream &o, Form const &rhs);

#endif
