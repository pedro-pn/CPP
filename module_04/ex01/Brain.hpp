/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:37:44 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/17 13:37:36 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {

	public:

		Brain(void);
		Brain(Brain const &brain);
		~Brain(void);

		Brain&	operator=(Brain const &brain);

		std::string		getIdeas(int const index) const;
		void			setIdeas(std::string *ideas);

	private:

		std::string	ideas[100];
};

#endif
