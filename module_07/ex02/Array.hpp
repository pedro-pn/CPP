/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:15:39 by pedro             #+#    #+#             */
/*   Updated: 2023/04/03 22:28:14 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <iostream>

template<typename T>
class Array {
	
	public:
	
		class OutOfRangeException : public std::exception {
			
			public:
				
				virtual const char	*what() const throw();
		};
	
		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(Array<T> const &rhs);
		~Array<T>(void);
		
		Array<T>&	operator=(Array<T> const &rhs);
		T&			operator[](size_t index) const;
		
		
		size_t	size(void) const;
		void	print(void) const;

	private:
	
		T				*_array;
		size_t const	_size;
};

# include "Array.tpp"

#endif /* ARRAY_HPP */
