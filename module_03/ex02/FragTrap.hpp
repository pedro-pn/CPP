/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:00:41 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/14 16:54:44 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	
	public:
		
		FragTrap(void);
		FragTrap(std::string const name);
		FragTrap(FragTrap const &fragtrap);
		~FragTrap(void);

		FragTrap&	operator=(FragTrap const &fragtrap);

		void	attack(const std::string& target);
		void	highFiveGuys(void);
};

#endif
