/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:44:48 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/17 10:41:23 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

	public:

		Cat(void);
		Cat(std::string const name);
		Cat(Cat const &cat);
		~Cat(void);

		Cat&	operator=(Cat const &cat);

		virtual void	makeSound(void) const;
	
	private:

		Brain	*brain;
};

#endif
