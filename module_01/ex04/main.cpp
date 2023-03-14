/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:20:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/13 22:09:54 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

int	handle_error(int argc) {
	switch (argc){
		case (1):
			std::cout << "Replace: missing <file> <s1> <s2>." << std::endl;
			break ;
		case (2):
			std::cout << "Replace: missing <s1> <s2>." << std::endl;
			break ;
		case(3):
			std::cout << "Replace: missing <s2>." << std::endl;
			break ;
		default:
			std::cout << "Replace: replace takes only <file> <s1> <s2>." << std::endl;
			break ;
	}
	return (1);
}

int	main(int argc, char *argv[]) {
	std::string			buffer;
	std::ifstream		file;
	
	if (argc < 4 || argc > 4)
		return (handle_error(argc));
	if (open_file(argv[1], file))
		return (1);
	buffer = read_and_replace(argv[2], argv[3], file);
	file.close();
	if (write_output(argv[1], buffer))
		return (1);
	return (0);
}
