/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:11:52 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/12 19:32:33 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <string>
# define DIGITS "0123456789"
# define CUTOFF 5

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

		//vector merge-insert sort
		void	_mergeInsertSortVector(int start, int end, int cutoff);

		// vector merge sort
		void	_mergeVector(int start, int middle, int end);

		//vector insert sort
		void	_insertionSortVector(int start, int end);
};

#endif
