/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:20:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/01 20:43:16 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

int	main(int argc, char *argv[]) {
	std::string			buffer;
	std::ifstream		file;
	
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (open_file(argv[1], file))
		return (1);
	buffer = read_and_replace(argv[2], argv[3], file);
	file.close();
	if (write_output(argv[1], buffer))
		return (1);
	return (0);
}
