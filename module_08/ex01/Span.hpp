/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:41:47 by pedro             #+#    #+#             */
/*   Updated: 2023/04/05 22:52:55 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {
	
	public:
	
		class FullSpanException : public std::exception {
			
			public:
			
				virtual const char	*what() const throw();	
		};
		
		class InsufficientElementException : public std::exception {
			public:
			
				virtual const char	*what() const throw();
		};
		
		class InsufficientSizeException : public std::exception {
			public:
			
				virtual const char	*what() const throw();
		};
	
		Span(void);
		Span(unsigned int n);
		Span(Span const &rhs);
		~Span(void);
		
		Span&	operator=(Span const &rhs);
		
		void	addNumber(int number);
		int		longestSpan(void) const;
		int		shortestSpan(void);
		
		template <class T>
		void	addMany(T begin, T end) {
			if ((std::distance(begin, end) + this->_vec.size()) > this->_capacity)
				throw Span::InsufficientSizeException();
			this->_vec.insert(this->_vec.end(), begin, end);
		}
		
	private:

		std::vector<int>		_vec;
		unsigned int const		_capacity;
		
		void	_sortVec(void);
};

#endif /* SPAN_HPP */
