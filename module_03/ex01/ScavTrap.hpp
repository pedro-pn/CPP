/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:08:04 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/14 10:33:21 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {

	public:
		
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &scavtrap);
		~ScavTrap(void);
		
		ScavTrap&	operator=(ScavTrap const &scavtrap);

		void	guardGate(void);
		void	attack(const std::string& target);
};

#endif
