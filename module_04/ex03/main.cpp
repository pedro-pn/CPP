/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:30:42 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/21 12:15:44 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	
	ICharacter* me = new Character("me");


	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;


	delete bob;
	delete me;
	delete src;

	std::cout << std::endl << "-----End of subject tests------" << std::endl;

	Character	jeff = Character("Jeff");

	MateriaSource	skills = MateriaSource();

	skills.learnMateria(new Ice());
	skills.learnMateria(new Cure());

	AMateria	*temp1 = skills.createMateria("ice");
	AMateria	*temp2 = skills.createMateria("ice");
	AMateria	*temp3 = skills.createMateria("ice");
	AMateria	*temp4 = skills.createMateria("ice");

	jeff.equip(temp1);
	jeff.equip(temp2);
	jeff.equip(temp3);
	jeff.equip(temp4);
	ICharacter	*chad =  new Character(jeff);
	ICharacter	*noa = new Character("Noa");
	jeff.unequip(0);
	jeff.unequip(1);
	jeff.unequip(2);
	jeff.unequip(3);
	jeff.equip(skills.createMateria("cure"));
	jeff.equip(skills.createMateria("cure"));
	jeff.equip(skills.createMateria("cure"));
	jeff.equip(skills.createMateria("cure"));

	std::cout << std::endl;
	jeff.use(0, *chad);
	chad->use(0, *noa);
	std::cout << std::endl;

	delete chad;
	delete noa;
	delete temp1;
	delete temp2;
	delete temp3;
	delete temp4;
	

}