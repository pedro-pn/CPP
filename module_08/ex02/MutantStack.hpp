/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:48:17 by pedro             #+#    #+#             */
/*   Updated: 2023/04/06 15:40:05 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

	public:

		typedef typename MutantStack<T>::container_type::iterator
			iterator;
		typedef typename MutantStack<T>::container_type::const_iterator
			const_iterator;
		typedef typename MutantStack<T>::container_type::reverse_iterator
			reverse_iterator;
		typedef typename MutantStack<T>::container_type::const_reverse_iterator
			const_reverse_iterator;

		MutantStack<T>();
		MutantStack<T>(MutantStack const &rhs);
		~MutantStack<T>();

		MutantStack<T>&	operator=(MutantStack<T> const &rhs);

		iterator				begin(void);
		iterator				end(void);
		const_iterator			begin(void) const;
		const_iterator			end(void) const;
		reverse_iterator		rbegin(void);
		reverse_iterator		rend(void);
		const_reverse_iterator	rbegin(void) const;
		const_reverse_iterator	rend(void) const;
};

# include "MutantStack.tpp"

#endif /* MUTANTSTACK_HPP*/
