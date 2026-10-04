#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
//     std::cout << std::endl;
// Fixed c(10);
// Fixed d(2);
// std::cout << "c: " << c << "d: " << d << std::endl;
// std::cout << (c + d) << std::endl;
// std::cout << (c - d) << std::endl;
// std::cout << (c * d) << std::endl;
// std::cout << (c / d) << std::endl;

// std::cout << std::endl;
// Fixed e(-4.2f);
// Fixed f(2);
// std::cout << "e: " << e << " f: " << f << std::endl;
// std::cout << (e * f) << std::endl;

// std::cout << std::endl;
// Fixed const g(10);
// Fixed const h(20);
// std::cout << "g: " << g << " h: " << h << std::endl;
// std::cout << (g < h) << std::endl;
// std::cout << (g > h) << std::endl;
// std::cout << (g <= h) << std::endl;
// std::cout << (g >= h) << std::endl;
// std::cout << (g == h) << std::endl;
// std::cout << (g != h) << std::endl;
