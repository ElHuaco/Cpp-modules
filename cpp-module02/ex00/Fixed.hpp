/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:43:42 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/25 11:34:14 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & rhs);
		~Fixed(void);

		Fixed				&operator=(Fixed const & rhs);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
	private:
		int					_fixed_point_value;
		static int const	_num_fractional_bits;
};
#endif
