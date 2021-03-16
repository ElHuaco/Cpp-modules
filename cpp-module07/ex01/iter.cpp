/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:48:41 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/03/16 10:25:35 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

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


static void foo_char(char const &x)
{
	std::cout << "This char ASCII code is: " << int(x) << std::endl;
	return;
}

static void foo_int(int const &x)
{
	std::cout << "This int would be char: " << char(x) << std::endl;
	return;
}

static void foo_float(float const &x)
{
	std::cout << "This float's nearest int is: " << int(x) << std::endl;
	return;
}

static void foo_string(std::string const &x)
{
	std::cout << "This string's length is: " << x.length() << std::endl;
	return;
}

int			main(void)
{
	std::cout << "============CHAR TEST===============" << std::endl;
	char c[5] = "ABCD";
	std::cout << "Calling iter with function template as argument..." << std::endl;
	my::iter(c, 5, print);
	std::cout << "Calling iter with foo_char..." << std::endl;
	my::iter(c, 5, foo_char);
	std::cout << "============INT TEST===============" << std::endl;
	int i[5] = {48, 49, 50, 51, 52};
	std::cout << "Calling iter with function template as argument..." << std::endl;
	my::iter(i, 5, print);
	std::cout << "Calling iter with foo_int..." << std::endl;
	my::iter(i, 5, foo_int);
	std::cout << "===========FLOAT TEST==============" << std::endl;
	float f[5] = {3.15, -42.042, 9090.9090, -360.6969, 0.001234};
	std::cout << "Calling iter with function template as argument..." << std::endl;
	my::iter(f, 5, print);
	std::cout << "Calling iter with foo_float..." << std::endl;
	my::iter(f, 5, foo_float);
	std::cout << "==========STRING TEST=============" << std::endl;
	std::string s[5] = {"Hola", "Paco", "Qué", "Tal", "eh?"};
	std::cout << "Calling iter with function template as argument..." << std::endl;
	my::iter(s, 5, print);
	std::cout << "Calling iter with foo_string..." << std::endl;
	my::iter(s, 5, foo_string);
	std::cout << "==========AWESOME TEST===========" << std::endl;
	int		tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];
	my::iter(tab, 5, print);
	my::iter(tab2, 5, print);
	return (0);
}
