/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:22:16 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/12 20:14:30 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>
# include <sstream>

static int	strtoi(std::string str)
{
	int i;

	std::istringstream(str) >> i;
	return (i);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Bad argument count. Need one literal value." << std::endl;
		return (1);
	}
	std::cout << "====================================" << std::endl;
	std::string input(argv[1]);
	{
		std::cout << "char: ";
		if ((input.find_first_not_of("+-0123456789.f") != std::string::npos))
		{
			if (input.length() != 1)
				std::cout << "impossible" << std::endl;
			else
				std::cout << input << std::endl;
		}
		else
		{
			int		temp = strtoi(input);
			if ((temp < 0) || (temp > 127))
				std::cout << "impossible";
			else if (isprint(static_cast<char>(temp)))
				std::cout << static_cast<char>(temp);
			else
				std::cout << "Non displayable";
			std::cout << std::endl;
		}
	}
	{
		std::cout << "int: ";
		if ((input == "nan") || (input == "inf") || (input == "-inf")
			|| (input == "inff") || (input == "-inff") || (input == "nanf")
			|| (input.find_first_not_of("+-0123456789.f") != std::string::npos))
			std::cout << "impossible" << std::endl;
		else
			std::cout << strtoi(input) << std::endl;
	}
	{
		std::cout << "float: ";
		if ((input == "nan") || (input == "inf") || (input == "-inf")
			|| (input == "inff") || (input == "-inff") || (input == "nanf"))
			std::cout << input << std::endl;
		else if (input.find_first_not_of("+-0123456789.f") != std::string::npos)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<float>(atof(argv[1])) << "f" << std::endl;
	}
	{
		std::cout << "double: "; 
		if ((input == "nan") || (input == "inf") || (input == "-inf")
			|| (input == "inff") || (input == "-inff") || (input == "nanf"))
			std::cout << input << std::endl;
		else if (input.find_first_not_of("+-0123456789.f") != std::string::npos)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<double>(atof(argv[1])) << std::endl;
	}
	std::cout << "====================================" << std::endl;
	return (0);
}
