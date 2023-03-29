/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:39:03 by pedro             #+#    #+#             */
/*   Updated: 2023/03/29 18:07:04 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include <iostream>
# include <string>
# include "ScalarConverter.hpp"

class Test : public ScalarConverter {
	
	public:
		static	void	testTypes(std::string const &n, std::string const &tittle);
		
	private:

		Test() {};
		void			_useTypes(std::string const &n, std::string const &tittle);
};

#endif
