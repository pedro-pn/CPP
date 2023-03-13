/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:00:41 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/13 20:09:07 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	
	public:
		
		FragTrap(std::string const name);
		FragTrap(FragTrap const &fragtrap);
		~FragTrap(void);

		FragTrap&	operator=(FragTrap const &fragtrap);

		void	highFiveGuys(void);
};

#endif
