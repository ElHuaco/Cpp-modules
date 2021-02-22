/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:27:43 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/22 13:29:54 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int		main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *str_ptr = &str;
	std::string &str_ref = str;
	std::cout << "POINTER: " << *str_ptr << std::endl;
	std::cout << "REFERENCE: " << str_ref << std::endl;
	return (0);
}
