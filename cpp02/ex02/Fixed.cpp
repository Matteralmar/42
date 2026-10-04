#include "Fixed.hpp"

Fixed::Fixed(void) : i(0){}

Fixed::Fixed(const int val){
	this->i = val << this->n;
}

Fixed::Fixed(const float val){
	this->i = roundf(val * (1 << this->n));
}

Fixed::Fixed(const Fixed &val) {
	this->i = val.getRawBits();
}

Fixed &Fixed:: operator=(const Fixed& val)
{
	this->i = val.getRawBits();
	return(*this);
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
	return this->i;
}

void Fixed::setRawBits(int const n)
{
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

bool Fixed::operator>(const Fixed &val) const{
	if(this->i > val.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &val) const{
	if(this->i < val.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &val) const{
	if(this->i <= val.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &val) const{
	if(this->i >= val.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &val) const{
	if(this->i == val.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &val) const{
	if(this->i != val.getRawBits())
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed &val) const{
	Fixed res;
	res.setRawBits(this->i + val.i);
	return res;
}

Fixed Fixed::operator-(const Fixed &val) const{
	Fixed res;
	res.setRawBits(this->i + val.i);
	return res;
}

Fixed Fixed::operator*(const Fixed &val) const{
	Fixed res;
	res.setRawBits((this->i * val.i) >> n);
	return res;
}

Fixed Fixed::operator/(const Fixed &val) const{
	Fixed res;
	res.setRawBits((this->i << n) / val.i);
	return res;
}

Fixed &Fixed::operator++(){
	this->i++;
	return *this;
}

Fixed &Fixed::operator--(){
	this->i--;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	this->i++;
	return tmp;
}

Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	this->i--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	if(a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	if(a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	if(a < b)
		return b;
	return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	if(a < b)
		return b;
	return a;
}