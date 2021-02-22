/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:26:15 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/22 09:53:44 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class	pony
{
	public:
		pony(void);
		pony(std::string name);
		~pony(void);
		std::string	get_status(void);
		std::string get_name(void);
		static pony	*ponyOnTheHeap(std::string name);
		static void	ponyOnTheStack(std::string name);
	private:
		std::string _status;
		std::string	_name;
};
