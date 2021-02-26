/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:11:56 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/26 10:04:31 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "The bigger of the two is: " << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "The smaller of the two is: " << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	Fixed c;
	c.setRawBits(2 << 8);
	Fixed const d (Fixed(10.0f) / Fixed(5));
	std::cout << "-------------------------------" << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "--c: " << --c << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "c--: " << c-- << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "The bigger of the two is: " << std::endl;
	std::cout << Fixed::max( c, d ) << std::endl;
	std::cout << "The smaller of the two is: " << std::endl;
	std::cout << Fixed::min( c, d ) << std::endl;
	std::cout << "Is c bigger than d? -> " << (c > d) << std::endl;
	std::cout << "Is c bigger than or equal to d? -> " << (c >= d) << std::endl;
	std::cout << "Is c smaller than d? -> " << (c < d) << std::endl;
	std::cout << "Is c smaller than or equal to d? -> " << (c <= d) << std::endl;
	std::cout << "c + d is: " << (c + d) << std::endl;
	std::cout << "c - d is: " << (c - d) << std::endl;
	return 0;
}
