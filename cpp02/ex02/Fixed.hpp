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
		bool operator>(const Fixed &val) const;
		bool operator<(const Fixed &val) const;
		bool operator>=(const Fixed &val) const;
		bool operator<=(const Fixed &val) const;
		bool operator==(const Fixed &val) const;
		bool operator!=(const Fixed &val) const;
		Fixed operator+(const Fixed &val) const;
		Fixed operator-(const Fixed &val) const;
		Fixed operator*(const Fixed &val) const;
		Fixed operator/(const Fixed &val) const;
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &outstream, Fixed const &val);

#endif