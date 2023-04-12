/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:32:38 by pedro             #+#    #+#             */
/*   Updated: 2023/04/12 14:12:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN {

	public:

		RPN(RPN const &rhs);
		RPN(void);
		RPN(std::string const &input);
		~RPN(void);

		RPN&	operator=(RPN const &rhs);
		
		int	calculate();

	private:

		std::stack<int>	_stack;
		std::string		_input;

		bool	_validateInput(void) const;
		int		_pop(void);
};

#endif /* RPN_HPP */
