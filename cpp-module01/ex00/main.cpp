/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:39:06 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/22 10:03:41 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

int		main(void)
{
	std::cout << "Creating now ponies 'Carol' and 'Twinkles' on the Stack";
	std::cout << std::endl;
	pony::ponyOnTheStack("Carol");
	pony::ponyOnTheStack("Twinkles");

	std::cout << "Creating now ponies 'Jumbo' and 'Chungo' on the Heap";
	std::cout << std::endl;
	pony *jumbo = pony::ponyOnTheHeap("Jumbo");
	pony *chungo = pony::ponyOnTheHeap("Chungo");
	std::cout << "Checking if Ponies destroyed after functions exit" << std::endl;
	std::cout << "Jumbo pointer: " << jumbo->get_name() << std::endl;
	std::cout << "Chungo pointer: " << chungo->get_name() << std::endl;
	return (0);
}
