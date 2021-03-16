/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:15:02 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/03/16 09:46:08 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

namespace my
{
	template <typename T> void swap(T *a, T *b)
	{
		T temp = *a;
		*a = *b;
		*b = temp;
		return;
	}
	template <typename T> T min(T const &a, T const &b)
	{
		return ((a < b) ? a : b);
	}
	
	template <typename T> T max(T const &a, T const &b)
	{
		return ((a > b) ? a : b);
	}
};

class Awesome
{
	public:
		Awesome(int n) : _n(n) {}
		int  getN(void) const { return (this->_n);}
		bool operator==(Awesome const &rhs) const{ return (this->_n == rhs._n);}
		bool operator!=(Awesome const &rhs) const{ return (this->_n != rhs._n);}
		bool operator>(Awesome const &rhs) const{ return (this->_n > rhs._n);}
		bool operator<(Awesome const &rhs) const{ return (this->_n < rhs._n);}
		bool operator>=(Awesome const &rhs) const{ return (this->_n >= rhs._n);}
		bool operator<=(Awesome const &rhs) const{ return (this->_n <= rhs._n);}
	private:
		int _n;
};

std::ostream	&operator<<(std::ostream &os, Awesome const &rhs)
{
	os << rhs.getN();
	return (os);
}

int		main(void)
{
	std::cout << "============CHAR TEST===============" << std::endl;
	char c1 = 'A';
	char c2 = 'B';
	std::cout << "Char #1: " << c1 << "; Char #2: " << c2 << std::endl;
	std::cout << "Swapping..." << std::endl;
	my::swap(&c1, &c2);
	std::cout << "Char #1: " << c1 << "; Char #2: " << c2 << std::endl;
	std::cout << "Min: " << my::min(c1, c2) << std::endl;
	std::cout << "Max: " << my::max(c1, c2) << std::endl;
	std::cout << "============INT TEST===============" << std::endl;
	int i1 = -1234;
	int i2 = 42;
	std::cout << "Int #1: " << i1 << "; Int #2: " << i2 << std::endl;
	std::cout << "Swapping..." << std::endl;
	my::swap(&i1, &i2);
	std::cout << "Int #1: " << i1 << "; Int #2: " << i2 << std::endl;
	std::cout << "Min: " << my::min(i1, i2) << std::endl;
	std::cout << "Max: " << my::max(i1, i2) << std::endl;
	std::cout << "===========FLOAT TEST=============" << std::endl;
	float f1 = -3.14152f;
	float f2 = 420.42f;
	std::cout << "Float #1: " << f1 << "; Float #2: " << f2 << std::endl;
	std::cout << "Swapping..." << std::endl;
	my::swap(&f1, &f2);
	std::cout << "Float #1: " << f1 << "; Float #2: " << f2 << std::endl;
	std::cout << "Min: " << my::min(f1, f2) << std::endl;
	std::cout << "Max: " << my::max(f1, f2) << std::endl;
	std::cout << "===========STRING TEST=============" << std::endl;
	std::string s1 = "Hola";
	std::string s2 = "Adios";
	std::cout << "String #1: " << s1 << "; String #2: " << s2 << std::endl;
	std::cout << "Swapping..." << std::endl;
	my::swap(&s1, &s2);
	std::cout << "String #1: " << s1 << "; String #2: " << s2 << std::endl;
	std::cout << "Min: " << my::min(s1, s2) << std::endl;
	std::cout << "Max: " << my::max(s1, s2) << std::endl;
	std::cout << "===========AWESOME TEST===========" << std::endl;
	Awesome a1(-1234);
	Awesome a2(42);
	std::cout << "Awesome #1: " << a1 << "; Awesome #2: " << a2 << std::endl;
	std::cout << "Swapping..." << std::endl;
	my::swap(&a1, &a2);
	std::cout << "Awesome #1: " << a1 << "; Awesome #2: " << a2 << std::endl;
	std::cout << "Min: " << my::min(a1, a2) << std::endl;
	std::cout << "Max: " << my::max(a1, a2) << std::endl;
	return(0);
}
