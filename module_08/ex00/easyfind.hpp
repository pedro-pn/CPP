/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:32:26 by pedro             #+#    #+#             */
/*   Updated: 2023/04/05 19:40:44 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <algorithm>

template <typename T>
int	easyfind(T haystack, int n) {
	
	typename T::iterator	result = std::find(haystack.begin(), haystack.end(), n);
	if (result == haystack.end())
		throw std::runtime_error("Could't find integer inside the container");
	return (*result);
}

#endif /* EASYFIND_HPP */
