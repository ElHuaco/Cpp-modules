/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:48:08 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/24 08:36:09 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int		main(void)
{
	srand(time(NULL));
	std::cout << "****Comprobemos creación en main en Stack y la funcion announce()****";
	std::cout << std::endl;	
	std::cout << "Creemos los zombies Randal y Grieves, de tipo tóxico y veloz usando setZombieType()";
	std::cout << std::endl;
		zombie	example1("Randal");
		zombie_event::setZombieType(&example1, "tóxico");
		example1.announce();
		zombie	example2("Grieves");
		zombie_event::setZombieType(&example2, "veloz");
		example2.announce();
	std::cout << "****Comprobemos creación con newZombie() en Heap****";
	std::cout << std::endl;
	std::cout << "Creemos a Magnus de tipo Librarian en la Heap" << std::endl;
		zombie	*example3 = zombie_event::newZombie("Magnus");
		zombie_event::setZombieType(example3, "Librarian");
		example3->announce();
		delete example3;
	std::cout << "****Comprobemos creación random de randomChump en Stack****";
	std::cout << std::endl;
		zombie_event::randomChump();
		zombie_event::randomChump();
		zombie_event::randomChump();
		zombie_event::randomChump();
		zombie_event::randomChump();
	std::cout << "****Comprobemos que Magnus ha sido liberado y ahora guarda basura****";
	std::cout << std::endl;
		example3->announce();
	return (0);
}
