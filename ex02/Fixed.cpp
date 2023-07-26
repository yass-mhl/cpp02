/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:52:33 by ymehlil           #+#    #+#             */
/*   Updated: 2023/07/26 11:04:18 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors and destructor

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &original)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = original;
	return ;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << _fractionalBits));
	return ;
}

Fixed::Fixed(const int value) : _value(value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_value = value << _fractionalBits;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

// Member functions

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return static_cast< float >(this->_value) / (1 << _fractionalBits);
}

int	Fixed::toInt( void ) const
{
	return this->_value >> _fractionalBits;
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

// Operators

std::ostream &	operator<<( std::ostream & os, Fixed const &rhs )
{
	os << rhs.toFloat();
	return os;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return this->_value > other._value;
}

bool	Fixed::operator<(const Fixed &other) const
{
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_value != other._value;
}


Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed&	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->operator++();
	return tmp;
}

Fixed&	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->operator--();
	return tmp;
}
