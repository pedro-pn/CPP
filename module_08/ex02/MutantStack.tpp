/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:54:28 by pedro             #+#    #+#             */
/*   Updated: 2023/04/06 14:47:30 by pedro            ###   ########.fr       */
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

/* ====================End of  MutantStack implementation==================== */

/* ===================MutantStack::Iterator implementation=================== */

template <typename T>
MutantStack<T>::iterator::iterator(T *p) : _p(p) {

}

template <typename T>
MutantStack<T>::iterator::iterator(iterator const &rhs) : _p(rhs._p) {

}

template <typename T>
MutantStack<T>::iterator::~iterator(void) {

}

template<typename T>
typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator=(iterator const &rhs) {
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator++() {
	++_p;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::iterator::operator++(int) {
	iterator temp(*this);
	++_p;
	return (temp);
}

template <typename T>
typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator--() {
	--_p;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::iterator::operator--(int) {
	iterator	temp(*this);

	--_p;
	return (temp);
}

template <typename T>
bool		MutantStack<T>::iterator::operator==(iterator const &rhs) const {
	return (_p == rhs._p);
}

template <typename T>
bool		MutantStack<T>::iterator::operator!=(iterator const &rhs) const {
	return (_p != rhs._p);
}

template <typename T>
T&			MutantStack<T>::iterator::operator*() {
	return (*_p);
}
