/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:27:36 by pedro             #+#    #+#             */
/*   Updated: 2023/04/04 10:13:37 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template<typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {
	std::cout << "Array default constructor was called!" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n) {
	std::cout << "Array constructor was called!" << std::endl;
	if (n > 0)
		this->_array = new T[n];
}

template<typename T>
Array<T>::~Array(void) {
	std::cout << "Array destructor was called!" << std::endl;
	delete [] this->_array;
}

template<typename T>
Array<T>::Array(Array<T> const &rhs) : _array(NULL), _size(rhs.size()) {
	std::cout << "Array copy constructor was called!" << std::endl;
	if (rhs.size() > 0)
		this->_array = new T[rhs.size()];
	*this = rhs;
}

template <typename T>
Array<T>&	Array<T>::operator=(Array<T> const &rhs) {
	std::cout << "Array assigment operator was called!" << std::endl;
	if (this == &rhs)
		return (*this);
	for (size_t i = 0; i < rhs.size(); i++) {
		(*this)[i] = rhs[i];
	}
	return (*this);
}

template<typename T>
T&			Array<T>::operator[](size_t index) const {
	if (index >= this->_size)
		throw Array<T>::OutOfRangeException();
	return (this->_array[index]);
}

template<typename T>
size_t	Array<T>::size(void) const {
	return (this->_size);
}

template<typename T>
void	Array<T>::print(void) const {
	std::cout << "[";
	for (size_t i = 0; i < this->_size; i++) {
		std::cout << (*this)[i];
		if (i < this->_size - 1)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

// exceptions

template<typename T>
const char	*Array<T>::OutOfRangeException::what() const throw() {
	return ("index out of range");
}
