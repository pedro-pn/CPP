/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:48:17 by pedro             #+#    #+#             */
/*   Updated: 2023/04/06 14:31:58 by pedro            ###   ########.fr       */
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
		
				iterator(T *p);
				iterator(iterator const &rhs);
				~iterator(void);

				iterator&	operator=(iterator const &rhs);
				iterator&	operator++();
				iterator	operator++(int);
				iterator&	operator--();
				iterator	operator--(int);
				bool		operator==(iterator const &rhs) const;
				bool		operator!=(iterator const &rhs) const;
				T&			operator*();

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