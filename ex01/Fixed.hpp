#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
    private :
        int _rawValue;
        static const int _fixedPoint = 8;
    public :
        Fixed();
        Fixed(const Fixed &copy);
        Fixed(const int value);
        Fixed(const float floatNumber);
        Fixed &operator=(const Fixed &f);
        ~Fixed();
        int getRawBits( void ) const { std::cout << "getRawBits member function called" << std::endl; return _rawValue; };
        void setRawBits( int const raw ) { _rawValue = raw; };
        float toFloat(void) const;
        int toInt(void) const;
        
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif