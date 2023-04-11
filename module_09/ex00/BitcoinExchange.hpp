/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:40:02 by pedro             #+#    #+#             */
/*   Updated: 2023/04/10 22:13:06 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <fstream>
# define JAN 1
# define FEV 2
# define MAR 3
# define APR 4
# define MAY 5
# define JUN 6
# define JUL 7
# define AUG 8
# define SET 9
# define OCT 10
# define NOV 11
# define DEC 12

class BitcoinExchange {
	
	public:
	
		BitcoinExchange(std::string	const &dataBase);
		BitcoinExchange(BitcoinExchange const &rhs);
		~BitcoinExchange(void);

		BitcoinExchange&	operator=(BitcoinExchange const &rhs);

		void	processInput(std::string const &fileName);

	private:
	
		std::map<int, double>	_dataBase;
		
		// datbase CSV functions
		void	_openDataBase(std::string const &fileName);
		void	_getDbLine(std::string const &line);

		bool	_checkDate(std::string const &date);
		bool	_checkValue(long int value);
		bool	_isInt(std::string const &n);
		bool	_isValue(std::string const &literal);
		double	_getClosestValue(int key);
		void	_getInputLine(std::string const &line);
};

#endif
