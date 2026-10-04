#include "Fixed.hpp"

Fixed::Fixed(void) : i(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int val){
	std::cout << "Int constructor called";
	this->i = val << this->n;
}

Fixed::Fixed(const float val){
	std::cout << "Float constructor called";
	this->i = roundf(val * (1 << this->n));
}

Fixed::Fixed(const Fixed &val) {
	std::cout << "Copy constructor called\n";
	this->i = val.getRawBits();
}

Fixed &Fixed:: operator=(const Fixed& val)
{
	std::cout << "Copy assignment operator called\n";
	this->i = val.getRawBits();
	return(*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member functioin called\n";
	return this->i;
}

void Fixed::setRawBits(int const n)
{
	std::cout << "setRawBits member function called \n";
	this->i = n;
}

int Fixed::toInt( void ) const{
	return this->i / (1 << this->n);
}

float Fixed::toFloat( void ) const{
	return (float)this->i / (1 << this->n);
}

std::ostream &operator<<(std::ostream &outstream, Fixed const &val)
{
	outstream << val.toFloat();
	return outstream;
}