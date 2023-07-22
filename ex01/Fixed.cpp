/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:52:33 by ymehlil           #+#    #+#             */
/*   Updated: 2023/07/22 20:17:23 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
	return ;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << _fractionalBits));
	return ;
}

Fixed::Fixed(const int value) : _value(value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << _fractionalBits;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

// Member function
int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

// Operators
Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return (*this);
}

float	Fixed::toFloat( void ) const
{
	return static_cast< float >(this->_value) / (1 << _fractionalBits);
}

int	Fixed::toInt( void ) const
{
	return this->_value >> _fractionalBits;
}

std::ostream &	operator<<( std::ostream & os, Fixed const &rhs )
{
	os << rhs.toFloat();
	return os;
}



