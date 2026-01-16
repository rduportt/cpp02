#include "Fixed.hpp"

Fixed::Fixed() : _rawValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : _rawValue(copy.getRawBits())
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _rawValue(value << _fixedPoint)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatNumber) : _rawValue(roundf(floatNumber * (1 << _fixedPoint)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        _rawValue = f.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

float Fixed::toFloat(void) const 
{
    return static_cast<float> (_rawValue) / (1 << _fixedPoint);
}

int Fixed::toInt(void) const
{
    return _rawValue >> _fixedPoint;
}

