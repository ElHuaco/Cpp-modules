/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:54:36 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/08 08:21:55 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

static void use_inventory(ICharacter *ptr, ICharacter *target)
{
	int i;

	std::cout << "~Using the materias on " << target->getName() << "~" << std::endl;
	i = -1;
	while (++i < INVENTORY_SIZE)
			ptr->use(i, *target);
	return;
}

static void	check_xp(AMateria *ptr)
{
	int			i;

	std::cout << "~Checking materia XP~" << std::endl;
	std::cout << ptr->getXP() << std::endl;
	return;
}

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	std::cout << "============Correct Use============" << std::endl;
	std::cout << std::endl;
	AMateria* tmp2;
	tmp2 = src->createMateria("ice");
	me->equip(tmp2);
	std::cout << me->getName() << " equipped " << tmp2->getType() << " materia." << std::endl;
	AMateria *tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);	
	std::cout << me->getName() <<" equipped " << tmp->getType() << " materia." << std::endl;
	std::cout << std::endl;
	ICharacter* bob = new Character("bob");
	use_inventory(me, bob);	
	check_xp(tmp);
	std::cout << std::endl;
	std::cout << "==========Inventory Sizes==========" << std::endl;
	std::cout << std::endl;
	std::cout << "Let's try to equip a (null) materia" << std::endl;
	me->equip(0);
	use_inventory(me, bob);
	check_xp(tmp);
	std::cout << std::endl;
	std::cout << "Let's try to equip an already equipped materia" << std::endl;
	me->equip(tmp);
	use_inventory(me, bob);
	check_xp(tmp);
	std::cout << std::endl;
	std::cout << "Let's try to equip 5 materias" << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);	
	tmp = src->createMateria("cure");
	me->equip(tmp);	
	tmp = src->createMateria("cure");
	me->equip(tmp);	
	use_inventory(me, bob);
	check_xp(tmp);
	std::cout << std::endl;
	std::cout << "Let's try to unequip -10 and 42 materia" << std::endl;
	me->unequip(-10);
	me->unequip(42);
	use_inventory(me, bob);
	std::cout << std::endl;
	std::cout << "Let's try to unequip twice a materia" << std::endl;
	me->unequip(0);
	me->unequip(0);
	use_inventory(me, bob);
	std::cout << "Was it deleted? type:" << tmp2->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "==========Incorrect Use==========" << std::endl;
	std::cout << "Let's try to use -10 and 42" << std::endl;
	me->use(-10, *bob);
	me->use(42, *bob);
	std::cout << std::endl;
	std::cout << "============Deep Copy============" << std::endl;
	std::cout << "Let's assign to a new character with an empty inventory";
	std::cout << std::endl << " and check that old materias were destroyed." << std::endl;
	std::cout << std::endl;
	Character newme("newme");
	tmp = src->createMateria("ice");
	newme.equip(tmp);
	use_inventory(&newme, bob);
	Character twome("twome");
	newme = twome;
	use_inventory(&newme, bob);
	std::cout << "Was it deleted? type:" << tmp->getType() << std::endl;

	delete bob;
	delete me;
	
	delete src;
	return 0;
}
