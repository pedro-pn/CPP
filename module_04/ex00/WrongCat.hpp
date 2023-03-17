/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:29:55 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/17 09:35:33 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:

		WrongCat(void);
		WrongCat(std::string const name);
		WrongCat(WrongCat const &wrongCat);
		~WrongCat(void);

		WrongCat&	operator=(WrongCat const &wrongCat);

		void	makeSound(void) const;
};

#endif
