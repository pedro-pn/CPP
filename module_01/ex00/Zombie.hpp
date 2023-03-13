/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:01:46 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/13 10:18:53 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

	public:

		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);

	private:

		std::string	name;
		
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif