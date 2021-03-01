/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:30:52 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/01 15:58:45 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
//#include <iostream>
//#include <string>

int		main(void)
{
	srand(time(NULL)); 
	FragTrap	alice;
	FragTrap	bob("bob");
	FragTrap	candance = FragTrap("candance");
	FragTrap	john("johny");
	std::cout << "---------------------------------" << std::endl;
	bob.rangedAttack(candance.getName());
	candance.takeDamage(bob.getRangedDMG());
	candance.meleeAttack(bob.getName());
	bob.takeDamage(candance.getMeleeDMG());
	alice.setName("alice");
	alice.vaulthunter_dot_exe("Johnny");
	john.takeDamage(alice.getRangedDMG());
	alice.vaulthunter_dot_exe("Johnny");
	john.takeDamage(alice.getRangedDMG());
	alice.vaulthunter_dot_exe("Johnny");
	john.takeDamage(alice.getRangedDMG());
	alice.vaulthunter_dot_exe("Johnny");
	john.takeDamage(alice.getRangedDMG());
	alice.vaulthunter_dot_exe("Johnny");
	std::cout << "---------------------------------" << std::endl;
	john.beRepaired(1);
	john.beRepaired(40);
	john.beRepaired(40);
	john.beRepaired(40);
	john.takeDamage(1000);
	std::cout << "---------------------------------" << std::endl;
	return (0);
}
