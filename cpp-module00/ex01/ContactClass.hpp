/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:30:30 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/22 08:42:21 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTCLASS_HPP
 # define CONTACTCLASS_HPP

 # include <string>

class	contact
{
	public:
		contact(void);
		~contact(void);

		void		fill_info(void);
		void		display_info(void) const;
		void		display_short_info(void) const;
		std::string	get_first_name(void) const;

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_login;
		std::string	_postal_address;
		std::string	_email_address;
		std::string	_phone_number;
		std::string _birthday_date;
		std::string	_favorite_meal;
		std::string	_underwear_color;
		std::string	_darkest_secret;
};
#endif
