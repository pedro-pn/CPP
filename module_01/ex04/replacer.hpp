/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:23:33 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/01 20:35:50 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <stdlib.h>

int			open_file(char	*filename, std::ifstream& file);
int			open_output(char *filename, std::ofstream& file);
int			write_output(char *filename, std::string buffer);
std::string	read_and_replace(std::string s1, std::string s2, std::ifstream &file);

#endif