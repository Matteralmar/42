#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int i;
		static const int n = 8;
	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed &val);
		Fixed &operator=(const Fixed &val);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &outstream, Fixed const &val);

#endif