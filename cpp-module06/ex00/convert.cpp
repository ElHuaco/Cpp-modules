/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:22:16 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/12 14:07:35 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>
# include <sstream>
# include <cctype>

static int	strtoi(std::string str)
{
	int i;

	std::istringstream(str) >> i;
	return (i);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Bad argument count. Need one literal value." << std::endl;
	std::string input(argv[1]);
	if (!isdigit(argv[1][0]))
	{
		if (!isprint(argv[1][0]))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << argv[1] << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		if (!isprint(argv[1][0]))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char*>(argv[1]) << std::endl;
		std::cout << "int: " << strtoi(input) << std::endl;
		std::cout << "float: " << static_cast<float>(atof(argv[1])) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(atof(argv[1])) << std::endl;
	}
}
