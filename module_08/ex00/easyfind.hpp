/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:32:26 by pedro             #+#    #+#             */
/*   Updated: 2023/04/05 11:30:21 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>

class NotFoundException : public std::exception {
	
	public:

		virtual	const char	*what() const throw();
};

template <typename T>
int	easyfind(T container, int n) {
	typename T::iterator	it;
	typename T::iterator	ite = container.end();
	for (it = container.begin(); it != ite; ++it)
	{
		if (*it == n)
			return (n);
	}
	throw NotFoundException();
}

# include "easyfind.tpp"

#endif /* EASYFIND_HPP */
