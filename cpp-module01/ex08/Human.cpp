/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:04:46 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/23 18:57:32 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void		Human::meleeAttack(std::string const &target)
{
	std::cout << "Melee attack on " << target << "!" << std::endl;
	return;
}

void		Human::rangedAttack(std::string const &target)
{
	std::cout << "Ranged attack on " << target << "!" << std::endl;
	return;
}

void		Human::intimidatingShout(std::string const &target)
{
	std::cout << target << " is intimidated!" << std::endl;
	return;
}

void		Human::action(std::string const &action_name, std::string const &target)
{
	//Array necesario si sólo podemos usar un "if" statement
	typedef void (Human::*method_arr)(std::string const &target);
	method_arr	method_arr_inst[] = {&Human::meleeAttack, &Human::rangedAttack,
		&Human::intimidatingShout};
	std::string action_str[] = {"meleeAttack", "rangedAttack",
		"intimidatingShout"};
	for (int i = -1; i < 3; ++i)
		if (action_name == action_str[i])
			(this->*(method_arr_inst[i]))(target);
	return;
}
