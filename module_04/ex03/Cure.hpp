/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:50:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/21 10:58:20 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {

	public:

		Cure(void);
		Cure(Cure const & rhs);
		~Cure(void);

		Cure&	operator=(Cure const & rhs);

		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif
