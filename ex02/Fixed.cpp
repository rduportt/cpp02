#include "Fixed.hpp"

Fixed::Fixed() : _rawValue(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : _rawValue(copy.getRawBits())
{
    //std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _rawValue(value << _fixedPoint)
{
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatNumber) : _rawValue(roundf(floatNumber * (1 << _fixedPoint)))
{
    //std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        _rawValue = f.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &f) const
{
    return (this->_rawValue > f._rawValue);
}

bool Fixed::operator<(const Fixed &f) const
{
    return (this->_rawValue < f._rawValue);
}

bool Fixed::operator>=(const Fixed &f) const
{
    return (this->_rawValue >= f._rawValue);
}

bool Fixed::operator<=(const Fixed &f) const
{
    return (this->_rawValue <= f._rawValue);
}

bool Fixed::operator==(const Fixed &f) const
{
    return (this->_rawValue == f._rawValue);
}

bool Fixed::operator!=(const Fixed &f) const
{
    return (this->_rawValue != f._rawValue);
}

Fixed Fixed::operator+(const Fixed &f) const
{
    Fixed result;
    result.setRawBits(this->_rawValue + f._rawValue);
    return (result);
}

Fixed Fixed::operator-(const Fixed &f) const
{
    Fixed result;
    result.setRawBits(this->_rawValue - f._rawValue);
    return (result);
}

Fixed Fixed::operator*(const Fixed &f) const
{
    Fixed result;
    long long multiplication = (long long)this->_rawValue * (long long)f._rawValue;
    result.setRawBits((int)multiplication >> _fixedPoint);
    return (result);
}

Fixed Fixed::operator/(const Fixed &f) const
{
    Fixed result;
    long long division = (long long)this->_rawValue <<_fixedPoint;
    result.setRawBits((int)(division / f._rawValue));
    return (result);
}

Fixed &Fixed::operator++()
{
    ++_rawValue;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++_rawValue;
    return temp;
}

Fixed &Fixed::operator--()
{
    --_rawValue;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --_rawValue;
    return(temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
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

