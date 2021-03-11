/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:26:25 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 11:19:06 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

static const char *tree = ""
"       ****\n"
"     ********\n"
"    **  ******\n"
"     *   ******     ******\n"
"         ******   *********\n"
"          ****  *****   ***\n"
"          ***  ***     **\n"
"    *************       *\n"
"  ******************\n"
" *****   H*****H*******\n"
" ***     H-___-H  *********\n"
"  ***    H     H      *******\n"
"   **    H-___-H        *****\n"
"     *   H     H         ****\n"
"         H     H         ***\n"
"         H-___-H         **\n"
"         H     H         *\n"
"         H-___-H\n";

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream outputfile(this->_target + "_shrubbery");
	if (outputfile.good() == false)
	{
		std::cerr << this->getName() << ": Error. I/O operation failed." << std::endl;
		return;
	}
	outputfile << tree;
	outputfile.close();
	return;
}
