/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:50:43 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/20 13:12:51 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

class AMateria {
	
	
	public:
	
		AMateria(void);
		AMateria(AMateria const & rhs);
		~AMateria(void);

		AMateria&	operator=(AMateria const & rhs);

		AMateria(std::string const & type);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:

		std::string	type;

};

#endif
