/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:43:42 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/25 18:18:44 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & rhs);
		Fixed(int const n);
		Fixed(float const n);
		~Fixed(void);

		Fixed				&operator=(Fixed const & rhs);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static int const	getNumFract(void);
	private:
		int					_fixed_point_value;
		static int const	_num_fractional_bits;
};

std::ostream				&operator<<(std::ostream &os, Fixed const &rhs);
#endif
