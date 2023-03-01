/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:43:40 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/01 10:21:44 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {

}

Weapon::~Weapon(void) {

}

const std::string& Weapon::getType(void) {
	std::string&	type_ref = this->type;
	return (type_ref);
}

void	Weapon::setType(std::string type) {
	this->type = type;
}
