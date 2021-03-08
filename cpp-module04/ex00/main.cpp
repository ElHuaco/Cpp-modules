/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:09:04 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/08 09:18:29 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Ork.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	Ork	chungo("Chungo");
	std::cout << robert << jim << joe << chungo;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(chungo);
	std::cout << "------------------------------------------" << std::endl;
	Victim *ptr = new Peon("Igorr");
	robert.polymorph(*ptr);
	delete ptr;
	std::cout << "------------------------------------------" << std::endl;
	return 0;
}
