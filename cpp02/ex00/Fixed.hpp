#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <iostream>

class Fixed
{
	private:
		int i;
		static const int n = 8;
	public:
		Fixed();
		Fixed(const Fixed &val);
		Fixed &operator=(const Fixed &val);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif