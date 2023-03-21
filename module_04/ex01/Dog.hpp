/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:14:52 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/21 11:54:52 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

	public:

		Dog(void);
		Dog(Dog const &dog);
		~Dog(void);

		Dog&	operator=(Dog const &dog);

		std::string	getBrainIdea(int const index) const;
		void		setBrainIdea(std::string const idea, int const index);

		virtual void	makeSound(void) const;

	private:

		Brain	*brain;
};

#endif
