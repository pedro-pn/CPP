/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:40:02 by pedro             #+#    #+#             */
/*   Updated: 2023/04/10 18:03:21 by pedro            ###   ########.fr       */
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

		void	openDataBase(std::string const &fileName);
		void			testeDb(std::string const &data);

	private:
	
		std::map<std::string, double>	_dataBase;
		
		bool			_checkDate(std::string const &date);
		bool			_checkValue(std::string const &value);
		bool			_isDouble(std::string const &data);
		void			_getDbLine(std::string const &line);
		bool			_checkInputLine(std::string const &fileName);
		bool			_isInt(std::string const &n);
		bool			_isValue(std::string const &literal);

};

#endif
