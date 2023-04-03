/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:13:36 by pedro             #+#    #+#             */
/*   Updated: 2023/04/03 19:57:32 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template<typename T>
void	iter(T *array, size_t length, void (*func)(T &)) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

#endif /* ITER_HPP */
