/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:20:59 by pedro             #+#    #+#             */
/*   Updated: 2023/03/30 11:42:08 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void) {
	Base	*p;

	p = generate();
	identify(p);
	identify(*p);
	
	p = generate();
	identify(p);
	identify(*p);
	
	
	p = generate();
	identify(p);
	identify(*p);
	
	
	p = generate();
	identify(p);
	identify(*p);
	
	
	p = generate();
	identify(p);
	identify(*p);
	
	return (0);
}
