/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:43:36 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 17:35:12 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy(void)
{
	int		i;
	Intern	*temp;

	i = -1;
	while (++i < NUM_OBS)
	{
		this->_block[i] = new OfficeBlock();
		temp = new Intern;
		this->_block[i]->setIntern(temp);
	}
	this->_queue = nullptr;
	return;
}

CentralBureaucracy::~CentralBureaucracy(void)
{
	int		i;

	i = -1;
	while (++i < NUM_OBS)
	{
		delete this->_block[i]->getIntern();
		delete this->_block[i];
	}
	delete[] this->_queue;
}

void		CentralBureaucracy::feedBureaucrat(Bureaucrat &brick)
{
	int		i;

	i = -1;
	while (++i < NUM_OBS)
	{
		if (this->_block[i]->getSigner() == nullptr)
		{
			this->_block[i]->setSigner(&brick);
			break;
		}
		else if (this->_block[i]->getExecutor() == nullptr)
		{
			this->_block[i]->setExecutor(&brick);
			break;
		}
		else
			continue;
	}
	return;
}

void		CentralBureaucracy::queueUp(std::string const &name)
{
	if (this->_queue == nullptr)
	{
		this->_queue = new std::string[1];
		this->_queue[0] = name;
		this->_queueSize = 1;
	}
	else
	{
		std::string		*temp = new std::string[this->_queueSize + 1];
		int		i = -1;
		while (++i < this->_queueSize)
			temp[i] = this->_queue[i];
		temp[i] = name;
		delete[] this->_queue;
		this->_queue = temp;
		this->_queueSize += 1;
	}
	return;
}

static std::string name_str[] = {"shrubbery creation", "robotomy request", 
	"presidential pardon"};

void		CentralBureaucracy::doBureaucracy(void) const
{
	int		random_number;
	int		i;
	int		j;

	i = -1;
	while (++i < this->_queueSize)
	{
		j = -1;
		while (++j < NUM_OBS)
		{
			random_number = rand() % 3;
			this->_block[j]->doBureaucracy(name_str[random_number],
				this->_queue[i]);
		}
	}
	return;
}
