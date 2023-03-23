/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:10:37 by pedro             #+#    #+#             */
/*   Updated: 2023/03/23 19:36:23 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	
	public:
	
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &rhs);
		~RobotomyRequestForm(void);
		
		RobotomyRequestForm&	operator=(RobotomyRequestForm const &rhs);
		
		void	beExecuted(void) const;
		
	private:
	
		std::string	_target;
};

#endif
