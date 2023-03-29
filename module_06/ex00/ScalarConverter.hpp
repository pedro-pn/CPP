/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:52:38 by pedro             #+#    #+#             */
/*   Updated: 2023/03/29 15:04:28 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter {
	
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &rhs);
		~ScalarConverter(void);
		
		ScalarConverter&	operator=(ScalarConverter const &rhs);
		static void convert(std::string const &literal);
		
		static bool	is_char(std::string const &literal);
		static bool	is_int(std::string const &literal);
		static bool	is_float(std::string const &literal);
		static bool	is_double(std::string const &literal);
	
	private:
	
		// bool	is_char(std::string const &literal);
		// bool	is_int(std::string const &literal);
		// bool	is_float(std::string const &literal);
		// bool	is_double(std::string const &literal);
};

#endif
