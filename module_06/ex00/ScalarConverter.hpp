/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:52:38 by pedro             #+#    #+#             */
/*   Updated: 2023/03/29 18:07:54 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# ifndef DEBUG
#  define DEBUG 1
# endif
# include <string>

class ScalarConverter {
	
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &rhs);
		~ScalarConverter(void);
		
		ScalarConverter&	operator=(ScalarConverter const &rhs);
		static void convert(std::string const &literal);
	
	protected:
	
		bool	_isChar(std::string const &literal);
		bool	_isInt(std::string const &literal);
		bool	_isFloat(std::string const &literal);
		bool	_isDouble(std::string const &literal);
};

#endif
