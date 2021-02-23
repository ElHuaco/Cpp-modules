/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:15:46 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/23 18:56:44 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Human.hpp"

int		main(void)
{
	Human	Bob;
	Human	Alice;
	Human	Candance;

	Bob.action("meleeAttack", "Cindy");
	Alice.action("rangedAttack", "Marty");
	Candance.action("intimidatingShout", "Johnny");
	return (0);
}
