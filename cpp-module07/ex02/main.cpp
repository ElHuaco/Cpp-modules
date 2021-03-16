/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:50:06 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/03/16 11:56:57 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

namespace my
{
	template <typename T> void iter(T arr[], int length, void (foo)(T const &))
	{
		int		i;

		i = -1;
		while (++i < length)
			foo(arr[i]);
		return;
	}
	template <typename T, template <typename> class Array>
		void iter(Array<T> &arr, int length, void (foo)(T const &))
	{
		std::cout << "Specialization called." << std::endl;
		int		i;

		i = -1;
		while (++i < length)
			foo(arr[i]);
		return;
	}
};

template <typename T> void print(T const &x)
{
	std::cout << x << std::endl;
	return;
}

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


int		main(void)
{
	std::cout << "============INT TEST===============" << std::endl;
	int *c = new int[5];
	my::iter(c, 5, print);
	Array<int> A1(5);
	my::iter(A1, 5, print);
	std::cout << "============STR TEST===============" << std::endl;
	std::string *s = new std::string[5];
	my::iter(s, 5, print);
	Array<std::string> A3(5);
	my::iter(A3, 5, print);
	std::cout << "==========AWESOME TEST=============" << std::endl;
	Awesome *a = new Awesome[5];
	my::iter(a, 5, print);
	Array<Awesome> A2(5);
	my::iter(A2, 5, print);

	delete[] c;
	delete[] a;
	delete[] s;
	return (0);
}
