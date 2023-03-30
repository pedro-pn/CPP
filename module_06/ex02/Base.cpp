/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:58:27 by pedro             #+#    #+#             */
/*   Updated: 2023/03/30 13:09:31 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {

}

static void	generateSeed(void) {
	static int	count = 0;
	
	if (count != 0)
		return ;
	std::srand(time(0));
	count = 1;
}

Base	*generate(void) {
	Base	*p;
	
	generateSeed();
	switch (std::rand() % 3) {
		case (0):
			p = new A();
			break ;
		case (1):
			p = new B();
			break ;
		case (2):
			p = new C();
			break ;
	}
	return (p);
}

void	identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "*p is a pointer to a A class" << std::endl;
	}
	else if (dynamic_cast<B *>(p)) {
		std::cout << "*p is a pointer to a B class" << std::endl;
	}
	else if (dynamic_cast<C *>(p)) {
		std::cout << "*p is a pointer to a C class" << std::endl;
	}
}
void	identify(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "p is a reference to a A class" << std::endl;
		return ;
	} catch (std::exception &e) {
	}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "p is a reference to a B class" << std::endl;
		return ;
	} catch (std::exception &e) {
	}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "p is a reference to a C class" << std::endl;
		return ;
	} catch (std::exception &e) {
	}
	std::cout << "p is not a A, a B or a C class" << std::endl;
}
