/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:24:20 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/24 08:44:18 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "ZombieHorde.hpp"
#include "Zombie.hpp"

int		main(void)
{
	srand(time(NULL));
	std::cout << "\t******Creemos una horda de 5******" << std::endl;
	ZombieHorde Horda(5);
	std::cout << "\t******Creemos una horda de 15******" << std::endl;
	ZombieHorde Horda2(15);
	return  (0);
}
