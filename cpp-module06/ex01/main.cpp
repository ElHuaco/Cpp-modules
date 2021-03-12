/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:47:19 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/12 17:23:15 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

struct Data
{
	std::string s1;
	int			n;
	std::string	s2;
};

static char		random_alphanum(void)
{
	int		random_number = rand() % 62;

	if (random_number < 10)
		return ('0' + random_number);
	else if (random_number < 36)
		return (55 + random_number);
	else
		return (61 + random_number);
}

static void		*serialize(void)
{
	void	*result = ::operator new (20);
	int		temp = rand() % 100;
	int		i = -1;

	std::cout << "=====Called serialize.=====" << std::endl;
	while (++i < 8)
		reinterpret_cast<char *>(result)[i] = random_alphanum();
	reinterpret_cast<int *>(result)[8] = temp;
	i = 11;
	while (++i < 20)
		reinterpret_cast<char *>(result)[i] = random_alphanum();
	i = -1;
	std::cout << "Raw[0-7]: ";
	while (++i < 8)
		std::cout << reinterpret_cast<char *>(result)[i];
	std::cout << std::endl;
	std::cout << "Raw[8-11]: ";
	std::cout << reinterpret_cast<int *>(result)[8] << std::endl;
	i = 11;
	std::cout << "Raw[12-20]: ";
	while (++i < 20)
		std::cout << reinterpret_cast<char *>(result)[i];
	std::cout << std::endl;

	std::cout << std::endl;
	return (result);
}

static Data		*deserialize(void *raw)
{
	std::cout << "====Called deserialize.====" << std::endl;
	Data		*result = new Data;
	int			i;

	result->s1.resize(8);
	result->s2.resize(8);
	i = -1;
	while (++i < 8)
		result->s1.at(i) = reinterpret_cast<char *>(temp)[i];
	result->n = reinterpret_cast<int *>(temp)[8];
	i = 11;
	while (++i < 20)
		result->s2.at(i - 12) = reinterpret_cast<char *>(temp)[i];
	return (result);
}

int		main(void)
{
	srand(time(NULL));

	Data	*test;
	void	*raw;

	raw = serialize();
	test = deserialize(raw);

	std::cout << "Data s1: " << test->s1 << std::endl;
	std::cout << "Data n: " << test->n << std::endl;
	std::cout << "Data s2: " << test->s2 << std::endl;
	std::cout << std::endl;

	delete reinterpret_cast<char *>(raw);
	delete test;
	return(0);
}
