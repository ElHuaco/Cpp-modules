/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:06:09 by alejandro         #+#    #+#             */
/*   Updated: 2021/02/26 10:19:27 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>

#define ARG_ERROR "Argument count != 1"
#define EMPTY_ERROR "Expression is empty."

static int	exit_error(char *error_str)
{
	std::cout << "eval_expr: Error. " << (char)error_str << std::endl;
	return (1);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
		return (exit_error(ARG_ERROR));
	std::string expression(argv[1]);
	if (expression == "")
		return (exit_error(EMPTY_ERROR));
}
