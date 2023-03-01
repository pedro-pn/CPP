/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:52:49 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/01 20:37:38 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

std::string	read_and_replace(std::string s1, std::string s2, std::ifstream &file) {
	std::stringstream	buffer;
	std::string			str_buffer;
	std::size_t			position;

	buffer << file.rdbuf();
	str_buffer = buffer.str();
	while (str_buffer.find(s1) != std::string::npos) {
		position = str_buffer.find(s1);
		str_buffer.erase(position, s1.size());
		str_buffer.insert(position, s2);
	}
	return (str_buffer);
}

int	write_output(char *filename, std::string buffer) {
	std::ofstream	outfile;

	if (open_output(filename, outfile))
		return (1);
	outfile << buffer;
	outfile.close();
	return (0);
}
