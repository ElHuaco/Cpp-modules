/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:45:06 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/20 13:30:33 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "easyfind.hpp"

static void print (int number)
{
	std::cout << number << std::endl;
	return;
}

int		main(void)
{
	int		needle1 = -42;
	int		needle2 = 2134;
	std::cout << "========VECTOR CONTAINER=========" << std::endl;
	std::vector<int>	vec(4, -42);
	for_each(vec.begin(), vec.end(), print);
	std::cout << "Finding " << needle1 << " in the container... ";
	std::vector<int>::const_iterator temp = easyfind(vec, needle1);
	if (temp != vec.end())
		print(*temp);
	else
		std::cout << "Didn't find "<< needle1 << std::endl;
	std::cout << "Finding " << needle2 << " in the container... ";
	temp = easyfind(vec, needle2);
	if (temp != vec.end())
		print(*temp);
	else
		std::cout << "Didn't find "<< needle2 << std::endl;
	std::cout << std::endl;
	std::cout << "========LIST CONTAINER=========" << std::endl;
	std::list<int>		lst;
	lst.push_back(1);
	lst.push_back(123456758);
	lst.push_back(-42);
	lst.push_back(90);
	for_each(lst.begin(), lst.end(), print);
	std::cout << "Finding " << needle1 << " in the container... ";
	std::list<int>::const_iterator temp2 = easyfind(lst, needle1);
	if (temp2 != lst.end())
		print(*temp2);
	else
		std::cout << "Didn't find "<< needle1 << std::endl;
	std::cout << "Finding " << needle2 << " in the container... ";
	temp2 = easyfind(lst, needle2);
	if (temp2 != lst.end())
		print(*temp2);
	else
		std::cout << "Didn't find "<< needle2 << std::endl;
	return (0);
}
