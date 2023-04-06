/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:04:43 by pedro             #+#    #+#             */
/*   Updated: 2023/04/06 16:37:28 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "MutantStack.hpp"
#include <list>

int	main(void) {
	
	// Mutant stack test
	std::cout << "\n========Test with MutantStack =======\n" << std::endl;
	
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	
	// Test with list
	std::cout << "\n========Test with List =======\n" << std::endl;
	
	std::list<int> mlist;
	
	
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator it2 = mlist.begin();
	std::list<int>::iterator ite2 = mlist.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::list<int> slist(mlist);
	
	// reverse iterator test
	std::cout << "\n=== Reverse Iterator test ===\n" << std::endl;
	
	MutantStack<int>::reverse_iterator it3 = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite3 = mstack.rend();
	++it3;
	--it3;
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}

	// Constructors test
	std::cout << "\n=== Copy contructor tests ===\n" << std::endl;
	
	MutantStack<int>	test;
	
	test.push(40);
	test.push(41);
	test.push(42);
	test.push(43);
	
	MutantStack<int>	copy(test);
	
	MutantStack<int>::iterator	copy_it = copy.begin();
	MutantStack<int>::iterator	copy_ite = copy.end();
	
	for (; copy_it != copy_ite; ++copy_it) {
		std::cout << "copy: " << *copy_it << std::endl;
	}
	
	// verify deep copy
	std::cout << "\n=== Deep copy verification ===\n" << std::endl;
	
	copy_it = copy.begin();
	*copy_it = 199;

	MutantStack<int>::iterator	test_it = test.begin();
	MutantStack<int>::iterator	test_ite = test.end();
	
	for (; copy_it != copy_ite; ++copy_it) {
		std::cout << "copy: " << *copy_it << std::endl;
	}
	
	for (; test_it != test_ite; ++test_it) {
		std::cout << "test: " << *test_it << std::endl;
	}
	

	return (0);
}
