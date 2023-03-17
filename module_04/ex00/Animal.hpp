/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:33:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/17 13:19:33 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "string"

class Animal {
	
	public:

		Animal(void);
		Animal(Animal const &animal);
		virtual ~Animal(void);

		Animal&	operator=(Animal const &animal);

		std::string	getType(void) const;
		void		setType(std::string const type);

		virtual void	makeSound(void) const;

	protected:

		std::string	type;
};

#endif
