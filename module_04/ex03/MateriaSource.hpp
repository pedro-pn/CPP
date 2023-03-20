/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:45:01 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/20 19:48:12 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"

class MateriaSource {

	public:
		
		MateriaSource(void);
		MateriaSource(MateriaSource const & rhs);

		MateriaSource&	operator=(MateriaSource const &rhs);
		virtual ~MateriaSource();
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);

	private:

		AMateria	*slots[4];
};

#endif
