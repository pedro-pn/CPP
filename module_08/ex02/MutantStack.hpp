/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:48:17 by pedro             #+#    #+#             */
/*   Updated: 2023/04/06 12:35:16 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	
	public:
	
		class iterator {
			
			public:

				iterator(T *p) : _p(p) {}
				iterator(iterator const &rhs) : _p(rhs._p) {}
				~iterator(void) {}

				iterator&	operator++() {++_p; return (*this);}
				iterator	operator++(int) {iterator temp(*this); ++_p; return (temp);}
				iterator&	operator--() {--_p; return (*this);}
				iterator	operator--(int) {iterator temp(*this); --_p; return (temp);}
				bool		operator==(iterator const &rhs) const {return (_p == rhs._p);}
				bool		operator!=(iterator const &rhs) const {return (_p != rhs._p);}
				T&			operator*() {return (*_p);}
			
			private:

				T	*_p;
		};
	
		MutantStack<T>();
		MutantStack<T>(MutantStack const &rhs);
		~MutantStack<T>();
		
		MutantStack<T>&	operator=(MutantStack<T> const &rhs);
		
		iterator	begin(void);
		iterator	end(void);
};

# include "MutantStack.tpp"

#endif /* MUTANTSTACK_HPP*/