/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:49:41 by ymehlil           #+#    #+#             */
/*   Updated: 2023/07/25 14:14:22 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &original);
		Fixed(const float value);
		Fixed(const int value);
		~Fixed();
		Fixed& operator=(const Fixed &other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
	
	private:
		int _value;
		static const int _fractionalBits = 8;

};
	std::ostream& operator<<(std::ostream& os, Fixed const &rhs);
#endif

