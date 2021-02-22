/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:13:54 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/22 13:11:57 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

zombie::zombie(void)
{
	return;
}

zombie::zombie(std::string name) : _name(name)
{
	return;
}

zombie::~zombie(void)
{
	return;
}

void	zombie::set_type(std::string type)
{
	this->_type = type;
}

void	zombie::set_name(std::string name)
{
	this->_name = name;
}

std::string	zombie::get_name(void) const
{
	return (this->_name);
}

void	zombie::announce(void) const
{
	std::cout << "<" << this->_name << " (";
	std::cout << this->_type << ")> Braiiiiiiiiiiiins..." << std::endl;
}
