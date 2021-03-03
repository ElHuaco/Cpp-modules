/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:28:04 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 13:18:02 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

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
	return (0);
}
