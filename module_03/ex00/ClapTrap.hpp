/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:41:43 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/14 10:20:39 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

	public:

		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &claptrap);
		~ClapTrap(void);
		
		ClapTrap&	operator=(ClapTrap const &claptrap);

		void 		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int			getHit(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

		void		setName(std::string name);

	private:

		std::string	Name;
		int			Hit;
		int			EnergyPoints;
		int			AttackDamage;
};

#endif
