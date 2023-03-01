/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:22:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/01 20:34:08 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

int		open_file(char	*filename, std::ifstream& file) {
	file.open(filename, std::ios::in);
	if (file.fail()) {
		std::cerr << "Couldn't open " << filename << "!" << std::endl;
		return (1);
	}
	return (0);
}

int		open_output(char *filename, std::ofstream& file) {
	std::string	s_filename = filename;
	s_filename += ".replace";
	file.open(s_filename.c_str(), std::ios::out | std::ios::trunc);
	if (file.fail()) {
		std::cerr << "Couldn't create " << s_filename << "!" << std::endl;
		return (1);
	}
	return (0);
}