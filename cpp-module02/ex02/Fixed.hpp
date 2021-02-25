/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:43:42 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/25 18:41:50 by aleon-ca         ###   ########.fr       */
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
		bool				operator>(Fixed const & rhs) const;
		bool				operator<(Fixed const & rhs) const;
		bool				operator>=(Fixed const & rhs) const;
		bool				operator<=(Fixed const & rhs) const;
		bool				operator==(Fixed const & rhs) const;
		bool				operator!=(Fixed const & rhs) const;
		Fixed				operator+(Fixed const & rhs) const;
		Fixed				operator-(Fixed const & rhs) const;
		Fixed				operator*(Fixed const & rhs) const;
		Fixed				operator/(Fixed const & rhs) const;
		Fixed				&operator++(void);
		Fixed				operator++(int);
		Fixed				&operator--(void);
		Fixed				operator--(int);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static int const	getNumFract(void);
		static Fixed		&min(Fixed &num1, Fixed &num2);
		static Fixed const	&min(Fixed const &num1, Fixed const &num2);
		static Fixed		&max(Fixed &num1, Fixed &num2);
		static Fixed const	&max(Fixed const &num1, Fixed const &num2);
	private:
		int					_fixed_point_value;
		static int const	_num_fractional_bits;
};

std::ostream				&operator<<(std::ostream &os, Fixed const &rhs);
#endif
