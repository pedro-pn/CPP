/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:23:43 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/02 13:03:18 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl	instance;

	instance.complain("DEBUG");
	instance.complain("WARNING");
	instance.complain("INFO");
	instance.complain("ERROR");
	instance.complain("nothing");
	return (0);
}
