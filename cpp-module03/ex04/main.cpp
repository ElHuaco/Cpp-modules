/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:30:52 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/02 12:17:23 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScravTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

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
	ScravTrap	gate;
	ScravTrap	porticulis("R2-D2");
	ScravTrap	rake(ScravTrap("Manwë"));
	std::cout << "---------------------------------" << std::endl;
	porticulis.rangedAttack(rake.getName());
	rake.takeDamage(porticulis.getRangedDMG());
	porticulis.meleeAttack(rake.getName());
	rake.takeDamage(porticulis.getMeleeDMG());
	std::cout << "---------------------------------" << std::endl;
	gate.setName("L0P3Z");
	gate.challengeNewcomer(rake.getName());
	gate.challengeNewcomer(rake.getName());
	gate.challengeNewcomer(rake.getName());
	std::cout << "---------------------------------" << std::endl;
	FragTrap	a("Doofus");
	ScravTrap	b("Rick Sanchez");
	NinjaTrap	c("Darkstar");
	NinjaTrap	d("Naruto");
	ClapTrap	sample("Arturito");
	std::cout << "---------------------------------" << std::endl;
	c.ninjaShoebox(a);
	std::cout << "---------------------------------" << std::endl;
	c.ninjaShoebox(b);
	std::cout << "---------------------------------" << std::endl;
	d.ninjaShoebox(sample);
	std::cout << "---------------------------------" << std::endl;
	d.ninjaShoebox(c);
	std::cout << "---------------------------------" << std::endl;
	SuperTrap	super("Man o' Steel");
	SuperTrap	thanos(SuperTrap("Thanos"));
	SuperTrap	silverhands = super;
	silverhands.setName("silverhands");
	std::cout << "---------------------------------" << std::endl;
	super.ninjaShoebox(b);
	super.vaulthunter_dot_exe(bob.getName());
	bob.takeDamage(super.getRangedDMG());
	silverhands.meleeAttack(thanos.getName());
	thanos.takeDamage(silverhands.getMeleeDMG());
	std::cout << "---------------------------------" << std::endl;
	return (0);
}
