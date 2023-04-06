/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:54:28 by pedro             #+#    #+#             */
/*   Updated: 2023/04/06 15:39:46 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/* ======================= MutantStack implementation ======================= */

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
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const {
	return (this->c.end());
}
template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend() {
	return (this->c.rend());
}
template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin() {
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend() const {
	return (this->c.rend());
}
template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin() const {
	return (this->c.rbegin());
}

/* ====================End of  MutantStack implementation==================== */
