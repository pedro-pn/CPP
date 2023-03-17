/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:14:52 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/17 10:41:42 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

	public:

		Dog(void);
		Dog(std::string const name);
		Dog(Dog const &dog);
		~Dog(void);

		Dog&	operator=(Dog const &dog);

		virtual void	makeSound(void) const;

	private:

		Brain	*brain;
};

#endif
