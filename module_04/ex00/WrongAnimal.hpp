/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:26:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/17 10:31:24 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "string"

class WrongAnimal {
	
	public:

		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &wrongAnimal);
		virtual ~WrongAnimal(void);

		WrongAnimal&	operator=(WrongAnimal const &wrongAnimal);

		std::string	getType(void) const;
		void		setType(std::string const type);

		void	makeSound(void) const;

	private:

		std::string	type;
};

#endif
