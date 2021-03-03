/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:09:04 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 10:38:24 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
//#include <cstdlib>

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);
	std::cout << "------------------------------------------" << std::endl;
	Victim *ptr = new Peon("Igorr");
	robert.polymorph(*ptr);
	delete ptr;
//	system("leaks 'HocusPocus.out'");
	std::cout << "------------------------------------------" << std::endl;
	return 0;
}
