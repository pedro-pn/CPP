/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:52:38 by pedro             #+#    #+#             */
/*   Updated: 2023/03/29 20:49:14 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# ifndef DEBUG
#  define DEBUG 1
# endif
# include <string>

enum e_types {
	CHAR_TYPE = 0,
	INT_TYPE = 1,
	FLOAT_TYPE = 2,
	DOUBLE_TYPE = 3
};

typedef struct s_types {
	char	_char;
	int		_int;
	float	_float;
	double	_double;
}			t_types;

class ScalarConverter {
	
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &rhs);
		~ScalarConverter(void);
		
		ScalarConverter&	operator=(ScalarConverter const &rhs);
		static void convert(std::string const &literal);
	
	protected:
	
		char	_char;
		int		_int;
		float	_float;
		double	_double;
	
		static bool	_isChar(std::string const &literal);
		static bool	_isInt(std::string const &literal);
		static bool	_isFloat(std::string const &literal);
		static bool	_isDouble(std::string const &literal);
		static int	assertType(std::string const &literal);
		
		static void	convertChar(std::string const &literal);
		static void	convertInt(std::string const &literal);
		static void	convertFloat(std::string const &literal);
		static void	convertDouble(std::string const &literal);
		static void	printConvertion(t_types const types);
};

#endif
