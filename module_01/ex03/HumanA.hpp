/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:48:42 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/13 10:36:44 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA {

	public:

		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void	attack(void);

	private:

		std::string	name;
		Weapon		&weapon;

};

#endif
