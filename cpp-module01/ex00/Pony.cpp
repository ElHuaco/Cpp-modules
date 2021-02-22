/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:27:37 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/22 09:51:23 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

pony::pony(void)
{
	this->_status = "Alive";
	this->_name = "Orphan";
	std::cout << this->_name << " is " << this->_status << std::endl;
	return;
}

pony::pony(std::string name) : _name(name)
{
	this->_status = "Alive";
	std::cout << this->_name << " is " << this->_status << std::endl;
	return;
}

pony::~pony(void)
{
	this->_status = "Dead";
	std::cout << this->_name << " is " << this->_status << std::endl;
	return;
}

std::string	pony::get_status(void)
{
	return (this->_status);
}

std::string pony::get_name(void)
{
	return  (this->_name);
}

pony		*pony::ponyOnTheHeap(std::string name)
{
	pony	*newborn = new pony(name);
	newborn->_status = "On the Heap";
	std::cout << newborn->_name << " is " << newborn->_status << std::endl;
	delete newborn;
	return newborn;
}

void		pony::ponyOnTheStack(std::string name)
{
	pony	newborn = pony(name);
	newborn._status = "On the Stack";
	std::cout << newborn._name << " is " << newborn._status << std::endl;
	return;
}

