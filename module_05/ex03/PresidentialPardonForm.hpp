/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:21:25 by pedro             #+#    #+#             */
/*   Updated: 2023/03/23 19:36:14 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	
	public:
	
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &rhs);
		~PresidentialPardonForm(void);
		
		PresidentialPardonForm&	operator=(PresidentialPardonForm const &rhs);
		
		void	beExecuted(void) const;
		
	private:
	
		std::string	_target;
};

#endif
