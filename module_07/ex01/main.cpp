/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:31:52 by pedro             #+#    #+#             */
/*   Updated: 2023/04/03 19:57:29 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template<typename T>
void	addTwo(T &x) {
	x += 2;
}

template<typename T>
void	print(T &n) {
	std::cout << n << std::endl;
}

int	main(void) {
	int		numbers[5] = {0, 2, 4, 5, 7};
	char	string[] = "tomate";
	float	numFloats[6] = {5.5f, 4.4f, 23.4f, 12.444f, 32.3f, 42.0f};

	iter<int>(numbers, (size_t) 5, addTwo<int>);
	iter<char>(string, (size_t) 6, addTwo<char>);
	iter<float>(numFloats, 6, addTwo<float>);

	iter<int>(numbers, 5, print<int>);
	std::cout << std::endl;
	iter<float>(numFloats, 6, print<float>);
	std::cout << std::endl;
	iter<char>(string, 6, print<char>);
	std::cout << std::endl;
	return (0);
}
