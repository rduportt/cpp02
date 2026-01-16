#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
    private :
        int _rawValue;
        static const int _fixedPoint = 8;
    public :
        Fixed();
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &f);
        ~Fixed();
        int getRawBits( void ) const { std::cout << "getRawBits member function called" << std::endl; return _rawValue; };
        void setRawBits( int const raw ) { _rawValue = raw; };
};

#endif