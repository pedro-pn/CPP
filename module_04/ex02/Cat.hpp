/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:44:48 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/21 11:59:38 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {

	public:

		Cat(void);
		Cat(Cat const &cat);
		~Cat(void);

		Cat&	operator=(Cat const &cat);

		std::string	getBrainIdea(int const index) const;
		void		setBrainIdea(std::string const idea, int const index);

		virtual void	makeSound(void) const;
	
	private:

		Brain	*brain;
};

#endif
