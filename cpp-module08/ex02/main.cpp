/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:37:14 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/18 13:13:59 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "mutantstack.hpp"
#include <ctime>
#include <cstdlib>

class Awesome
{
	public:
		Awesome(void) :_n(42) {return;}
		int get(void) const {return this->_n;}
	private:
		int _n;
};

std::ostream &operator<<(std::ostream &os, Awesome const &rhs)
{
	os << rhs.get();
	return (os);
}

template <typename T> void print(MutantStack<T> mstack)
{
	if ((mstack.empty() == true) || (mstack.size() == 0))
		return;
	std::cout << "Printing the stack..." << std::endl;
	typename MutantStack<T>::iterator it = mstack.begin();
	typename MutantStack<T>::iterator ite = mstack.end();
	while (it != ite - 1)
	{
		std::cout << "|  " << *it << std::endl;
		++it;
	}
	std::cout << "v  "<< *it << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	return;
}

int		main(void)
{
	srand(time(NULL));
	std::cout << "========INT STACK==========" << std::endl;
	std::cout << "========CHECK PUSH=========" << std::endl;
	MutantStack<int> mstack;
	unsigned int i = 0;
	while (i++ < 50)
		mstack.push(rand() % 100 - 50);
	print(mstack);
	std::cout << "Is the stack empty?  " << std::boolalpha << mstack.empty() << std::endl;
	std::cout << std::endl;
	std::cout << "========STR STACK==========" << std::endl;
	std::cout << "========CHECK POP==========" << std::endl;
	MutantStack<std::string> fstack;
	fstack.push("Hola don pepito");
	fstack.push("Hola don josé");
	fstack.push("y tal");
	print(fstack);
	std::cout << std::endl;
	std::cout << "-------stack popped-------" << std::endl;
	fstack.pop();
	print(fstack);
	std::cout << std::endl;
	std::cout << "-------stack popped-------" << std::endl;
	fstack.pop();
	print(fstack);
	std::cout << std::endl;
	std::cout << "-------stack popped-------" << std::endl;
	fstack.pop();
	print(fstack);
	std::cout << "Is the stack empty?  " << std::boolalpha << fstack.empty() << std::endl;
	std::cout << std::endl;
	std::cout << "======AWESOME STACK=======" << std::endl;
	std::cout << "======COMPLEX TYPE========" << std::endl;
	MutantStack<Awesome> Astack;
	Astack.push(Awesome());
	Astack.push(Awesome());
	Astack.push(Awesome());
	print(Astack);
	std::cout << std::endl;
	std::cout << "-------stack popped-------" << std::endl;
	Astack.pop();
	print(Astack);
	std::cout << std::endl;
	std::cout << "-------stack popped-------" << std::endl;
	Astack.pop();
	print(Astack);
	std::cout << std::endl;
	std::cout << "-------stack popped-------" << std::endl;
	Astack.pop();
	print(Astack);
	std::cout << "Is the stack empty?  " << std::boolalpha << Astack.empty() << std::endl;
	std::cout << std::endl;
	return (0);
}
