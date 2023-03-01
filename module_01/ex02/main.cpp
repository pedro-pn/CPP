/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:11:46 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/28 23:28:07 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string *str_ptr = &str;
	std::string &str_ref = str;

	std::cout << "str: " << &str << std::endl;
	std::cout << "str_ptr: " << str_ptr << std::endl;
	std::cout << "str_ref: " << &str_ref << std::endl;
	
	std::cout << "str: " << str << std::endl;
	std::cout << "str_ptr: " << *str_ptr << std::endl;
	std::cout << "str_ref: " << str_ref << std::endl;

	return (0);
}
