/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:28:04 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/08 09:37:42 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Choppa.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Ork.hpp"

int		main(void)
{
	std::cout << "------------------------------------------" << std::endl;
	Enemy			*mancubus = new SuperMutant;
	Enemy			*phareka = new RadScorpion;
	Character		smurf("Magnus Calgar");
	PlasmaRifle		phosphorGun;
	PowerFist		omniAxe;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << smurf << std::endl;
	smurf.attack(mancubus);
	smurf.equip(&phosphorGun);
	std::cout << smurf << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	smurf.attack(mancubus);
	std::cout << smurf << std::endl;
	smurf.attack(mancubus);
	std::cout << smurf << std::endl;
	smurf.attack(mancubus);
	std::cout << smurf << std::endl;
	smurf.attack(mancubus);
	std::cout << smurf << std::endl;
	smurf.attack(mancubus);
	std::cout << smurf << std::endl;
	smurf.attack(mancubus);
	std::cout << smurf << std::endl;
	smurf.attack(mancubus);
	std::cout << smurf << std::endl;
	smurf.attack(mancubus);
	std::cout << smurf << std::endl;
	smurf.attack(mancubus);
	std::cout << smurf << std::endl;
	smurf.attack(mancubus);
	smurf.recoverAP();	
	std::cout << smurf << std::endl;
	smurf.attack(mancubus);
	std::cout << smurf << std::endl;
	smurf.attack(mancubus);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << smurf << std::endl;	
	smurf.recoverAP();	
	std::cout << smurf << std::endl;
	smurf.recoverAP();	
	std::cout << smurf << std::endl;
	smurf.recoverAP();	
	std::cout << smurf << std::endl;
	smurf.recoverAP();	
	std::cout << smurf << std::endl;
	smurf.recoverAP();	
	std::cout << smurf << std::endl;
	smurf.equip(&omniAxe);
	std::cout << smurf << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	smurf.attack(phareka);
	std::cout << smurf << std::endl;
	smurf.attack(phareka);
	std::cout << smurf << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	Enemy	*boi = new Ork;
	Choppa	handaxe;
	smurf.equip(&handaxe);
	smurf.attack(boi);
	std::cout << smurf << std::endl;
	smurf.attack(boi);
	std::cout << smurf << std::endl;
	smurf.attack(boi);
	std::cout << smurf << std::endl;
	smurf.attack(boi);
	std::cout << smurf << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	return (0);
}
