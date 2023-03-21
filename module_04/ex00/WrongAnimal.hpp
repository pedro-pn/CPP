/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:26:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/21 11:50:46 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "string"

class WrongAnimal {
	
	public:

		WrongAnimal(void);
		WrongAnimal(std::string const &type);
		WrongAnimal(WrongAnimal const &wrongAnimal);
		virtual ~WrongAnimal(void);

		WrongAnimal&	operator=(WrongAnimal const &wrongAnimal);

		std::string	getType(void) const;
		void		setType(std::string const type);

		void	makeSound(void) const;

	protected:

		std::string	type;
};

#endif
