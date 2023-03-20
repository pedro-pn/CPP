/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:33:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/20 11:25:27 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "string"

class AAnimal {
	
	public:

		AAnimal(void);
		AAnimal(AAnimal const &animal);
		virtual ~AAnimal(void);

		AAnimal&	operator=(AAnimal const &animal);

		std::string	getType(void) const;
		void		setType(std::string const type);

		virtual void	makeSound(void) const = 0;

	protected:

		std::string	type;
};

#endif
