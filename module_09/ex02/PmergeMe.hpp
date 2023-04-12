/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:11:52 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/12 18:47:20 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <string>
# define DIGITS "0123456789"

class PmergeMe {

	public:

		PmergeMe(void);
		PmergeMe(char **input);
		PmergeMe(std::string const &input);
		PmergeMe(PmergeMe const &rhs);
		~PmergeMe(void);

		PmergeMe&	operator=(PmergeMe const &rhs);
		std::list<int>		_list;
		std::vector<int>	_vector;

	private:

		void	_parseInput(char **input);
		void	_mergeSortVector(std::vector<int> &vector, int start, int end);
		void	_mergeVector(std::vector<int> &vector, int start, int middle, int end);
};

#endif
