/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:30:24 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 18:03:45 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

static std::string name_arr[] = {"Pepe", "Pony", "Davyy", "Sseth", "Khorne",
	"Nurgle", "Tzeentch", "Bipiity", "Morganius", "Fabulonious", "Gandalf"};

static std::string target_arr[] = {"Mercury", "Venus", "Earth", "Mars",
	"Jupiter", "Urano", "Saturno", "Neptuno", "Plutón"};

int	main(void)
{
	srand(time(NULL));
	int	i = -1;
	CentralBureaucracy		UAM;
	Bureaucrat				**bureaucrat_arr = new Bureaucrat*[20];
	while (++i < 20)
		bureaucrat_arr[i] = new Bureaucrat(name_arr[rand() % 11], rand() % 149 + 1);
	i = -1;
	while (++i < 20)
		UAM.feedBureaucrat(*(bureaucrat_arr[i]));
	i = -1;
	while (++i < 100)
		UAM.queueUp(target_arr[rand() % 9]);
	UAM.doBureaucracy();
	i = -1;
	while (++i < 20)
		delete bureaucrat_arr[i];
	delete[] bureaucrat_arr;
	return (0);
}
