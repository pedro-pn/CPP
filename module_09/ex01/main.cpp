/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:31:20 by pedro             #+#    #+#             */
/*   Updated: 2023/04/11 17:09:43 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	checkArgs(int argc) {
	if (argc < 2) {
		std::cerr << "RPN error: missing RPN expression" << std::endl;
		return (1);
	}
	if (argc > 2) {
		std::cerr << "RPN error: only one statement is necessary" << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[]) {
	if (checkArgs(argc))
		return (1);

	try {
		RPN	rpn(argv[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
