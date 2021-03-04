/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 08:38:24 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/04 11:21:12 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	std::cout << "-----------Entering the loop-------------" << std::endl;
	for (int i = 0; i < vlc->getCount(); ++i)
	{
	std::cout << "-----------Marine: " << i << "---------------------" << std::endl;
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << "---------Invalid ISpaceMarine *----------" << std::endl;
	std::cout << "Adding a (null) marine and one already in the Squad." << std::endl;
	vlc->push(0);
	vlc->push(bob);
	std::cout << "Marine count is: " << vlc->getCount() << std::endl;
	std::cout << "-------Invalid getUnit() parameter--------" << std::endl;
	std::cout << "Trying to access out-of-bounds marines." << std::endl;
	std::cout << "Marine -42: " << vlc->getUnit(-42) << std::endl;
	std::cout << "Marine 42069: " << vlc->getUnit(42069) << std::endl;
	std::cout << "------------Copy Constructor-------------" << std::endl;
	std::cout << "Creating a new squad with copy constructor" << std::endl;
	ISpaceMarine	*tom = new AssaultTerminator;
	Squad *nlc = new Squad;
	nlc->push(tom);
	Squad wlc(*nlc);
	std::cout << "-----------Entering the loop-------------" << std::endl;
	for (int i = 0; i < wlc.getCount(); ++i)
	{
	std::cout << "-----------Marine: " << i << "---------------------" << std::endl;
		ISpaceMarine* cur = wlc.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << "-----------Assignment Operator------------" << std::endl;
	std::cout << "Assigning the old squad to the copy-constructed" << std::endl;
	*nlc = wlc;
	std::cout << "-----------Entering the loop-------------" << std::endl;
	for (int i = 0; i < wlc.getCount(); ++i)
	{
	std::cout << "-----------Marine: " << i << "---------------------" << std::endl;
		ISpaceMarine* cur = wlc.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << "-----------------------------------------" << std::endl;
	delete nlc;
	delete vlc;
	return 0;
}
