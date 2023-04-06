/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:14:27 by pedro             #+#    #+#             */
/*   Updated: 2023/04/03 17:47:36 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &a, T &b) {
	T	temp = a;

	a = b;
	b = temp;
}

template<typename T>
T const &	min(T const &a, T const &b) {
	return (a < b ? a : b);
}

template<typename T>
T const &	max(T const &a, T const &b) {
	return (a > b ? a : b);
}

#endif /* WHATEVER_HPP */