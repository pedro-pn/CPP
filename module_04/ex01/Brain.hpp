/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:37:44 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/20 10:02:32 by ppaulo-d         ###   ########.fr       */
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
		void			setIdeas(std::string const idea, int const index);

	private:

		std::string	ideas[100];
};

#endif
