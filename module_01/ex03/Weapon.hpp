/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:40:21 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/01 10:21:52 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {

	public:

		Weapon(std::string type);
		~Weapon(void);
		
		const std::string&	getType(void);
		void				setType(std::string type);

	private:

		std::string	type;
};

#endif