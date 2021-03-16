/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:50:06 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/03/16 16:44:27 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

namespace my
{
	template <typename T>
		void iter(T arr[], int length, void (foo)(T const &))
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
		void set(int n) {this->_n = n; return;}
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
	std::cout << "---------Default Array-------------" << std::endl;
	my::iter(c, 5, print);
	std::cout << "----------Array Class--------------" << std::endl;
	Array<int> A1(5);
	my::iter(A1, A1.size(), print);
	std::cout << "-------------Copia cambiada-----------" << std::endl;
	Array<int> I1(A1);
	I1[0] = 1234;
	my::iter(I1, I1.size(), print);
	std::cout << "---------------Antigua---------------" << std::endl;
	my::iter(A1, A1.size(), print);
	std::cout << "============STR TEST===============" << std::endl;
	std::string *s = new std::string[5];
	std::cout << "---------Default Array-------------" << std::endl;
	my::iter(s, 5, print);
	std::cout << "----------Array Class--------------" << std::endl;
	Array<std::string> A3(5);
	my::iter(A3, A3.size(), print);
	std::cout << "-------------Copia cambiada-----------" << std::endl;
	Array<std::string> I2(A3);
	I2[0] = "copiada cambiada";
	my::iter(I2, I2.size(), print);
	std::cout << "---------------Antigua---------------" << std::endl;
	my::iter(A3, A3.size(), print);
	std::cout << "==========AWESOME TEST=============" << std::endl;
	Awesome *a = new Awesome[5];
	std::cout << "---------Default Array-------------" << std::endl;
	my::iter(a, 5, print);
	std::cout << "----------Array Class--------------" << std::endl;
	Array<Awesome> A2(5);
	my::iter(A2, A2.size(), print);
	std::cout << "-------------Copia cambiada-----------" << std::endl;
	Array<Awesome> I3(A2);
	I3[0].set(69);
	my::iter(I3, I3.size(), print);
	std::cout << "---------------Antigua---------------" << std::endl;
	my::iter(A2, A2.size(), print);
	std::cout << "===========EXCEPTION TEST==========" << std::endl;
	try
	{
		std::cout << A2[6] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << A2[-6] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete[] c;
	delete[] a;
	delete[] s;
	return (0);
}
