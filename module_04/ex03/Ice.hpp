/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:12:00 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/21 10:58:26 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {

	public:

		Ice(void);
		Ice(Ice const & rhs);
		~Ice(void);

		Ice&	operator=(Ice const & rhs);

		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif
