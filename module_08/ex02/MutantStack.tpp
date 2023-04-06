/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:54:28 by pedro             #+#    #+#             */
/*   Updated: 2023/04/06 12:44:55 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/* ===================== MutantStack implementation ========================= */

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
	
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &rhs) : std::stack<T>() {
	*this = rhs;
}

template <typename T>
MutantStack<T>::~MutantStack(){
	
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack<T> const &rhs) {
	if (this == &rhs)
		return (*this);
	this->_stack = rhs._stack;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return (MutantStack<T>::iterator(&std::stack<T>::top() - this->size() + 1));
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return ( MutantStack<T>::iterator(&std::stack<T>::top() + 1));
}

/* ====================End of  MutantStack implementation =================== */
