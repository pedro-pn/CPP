/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:18:18 by pedro             #+#    #+#             */
/*   Updated: 2023/03/30 10:37:58 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

Data	fillData(void) {
	Data	data;

	data.string = "Sem tomate não é feijoada";
	data._char = 'f';
	data._float = 42.66f;
	data._int = 42;
	return (data);
}

void	printData(Data *data) {
	std::cout << "\t" << data->string << std::endl;
	std::cout << "\t" << data->_char << std::endl;
	std::cout << "\t" << data->_float << std::endl;
	std::cout << "\t" << data->_int << std::endl;
}

int	main(void) {
	Data		data;
	uintptr_t	ptr;
	Data		*newData;
	
	std::cout << "===STACK variable test ==" << std::endl;
	data = fillData();
	std::cout << "Before serialize:" << std::endl;
	printData(&data);
	ptr = Serializer::serialize(&data);
	newData = Serializer::deserialize(ptr);
	std::cout << "After serialize:" << std::endl;
	printData(newData);
	std::cout << std::endl;
	
	Data		*dataPointer;
	uintptr_t	ptr_2;
	Data		*newData_2;
	
	dataPointer = new Data;
	*dataPointer = fillData();
	std::cout << "===HEAP variable test ==" << std::endl;
	std::cout << "Before serialize:" << std::endl;
	printData(dataPointer);
	ptr_2 = Serializer::serialize(dataPointer);
	newData_2 = Serializer::deserialize(ptr_2);
	std::cout << "After serialize:" << std::endl;
	printData(newData_2);
	
	delete dataPointer;
	return (0);
}
