/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:01:46 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/13 10:26:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

	public:

		Zombie(void);
		~Zombie();

		void	announce(void);
		void	setName(std::string name);

	private:

		std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
