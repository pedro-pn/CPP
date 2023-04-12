/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:40:02 by pedro             #+#    #+#             */
/*   Updated: 2023/04/12 14:12:24 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <fstream>
# define JAN "01"
# define FEV "02"
# define APR "04"
# define JUN "06"
# define SET "09"
# define NOV "11"
# define DEC "12"
# define FYEAR "1900"
# define LYEAR "2023"

class BitcoinExchange {
	
	public:
	
		BitcoinExchange(std::string	const &dataBase);
		BitcoinExchange(BitcoinExchange const &rhs);
		~BitcoinExchange(void);

		BitcoinExchange&	operator=(BitcoinExchange const &rhs);

		void	processInput(std::string const &fileName);

	private:
	
		std::map<std::string, double>	_dataBase;
		
		// datbase CSV functions
		void	_openDataBase(std::string const &fileName);
		void	_getDbLine(std::string const &line);
		bool	_checkDbHeader(std::string const &line);

		bool	_checkInputHeader(std::string const &line);
		bool	_checkDate(std::string const &date);
		bool	_checkValue(long int value);
		bool	_isInt(std::string const &n);
		bool	_isValue(std::string const &literal);
		double	_getClosestValue(std::string const &key);
		void	_getInputLine(std::string const &line);
};

#endif /* BITCOINEXCHANGE_HPP */
