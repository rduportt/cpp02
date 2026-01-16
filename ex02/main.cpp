#include "Fixed.hpp"
#include <iostream>
#include <limits>

int main() {
    
    std::cout << "\n=== TESTS DES OPÉRATEURS DE COMPARAISON ===\n";
    Fixed e(5);
    Fixed f(10);
    
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "e > f: " << (e > f) << std::endl;
    std::cout << "e < f: " << (e < f) << std::endl;
    std::cout << "e >= f: " << (e >= f) << std::endl;
    std::cout << "e <= f: " << (e <= f) << std::endl;
    std::cout << "e == f: " << (e == f) << std::endl;
    std::cout << "e != f: " << (e != f) << std::endl;
    
    Fixed g(10);
    std::cout << "\nf = " << f << ", g = " << g << std::endl;
    std::cout << "f == g: " << (f == g) << std::endl;
    std::cout << "f != g: " << (f != g) << std::endl;
    
    std::cout << "\n=== TESTS DES OPÉRATEURS ARITHMÉTIQUES ===\n";
    Fixed h(2.5f);
    Fixed i(1.5f);
    
    std::cout << "h = " << h << ", i = " << i << std::endl;
    std::cout << "h + i = " << (h + i) << std::endl;
    std::cout << "h - i = " << (h - i) << std::endl;
    std::cout << "h * i = " << (h * i) << std::endl;
    std::cout << "h / i = " << (h / i) << std::endl;
    
    std::cout << "\n10 + 2.5 = " << (Fixed(10) + Fixed(2.5f)) << std::endl;
    std::cout << "10 - 2.5 = " << (Fixed(10) - Fixed(2.5f)) << std::endl;
    std::cout << "10 * 2.5 = " << (Fixed(10) * Fixed(2.5f)) << std::endl;
    std::cout << "10 / 2.5 = " << (Fixed(10) / Fixed(2.5f)) << std::endl;
    
    std::cout << "\n=== TESTS DES OPÉRATEURS D'INCRÉMENT/DÉCRÉMENT ===\n";
    Fixed j(0);
    
    std::cout << "j initial: " << j << std::endl << std::endl;
    std::cout << "++j: " << ++j << std::endl;
    std::cout << "j après ++j: " << j << std::endl << std::endl;
    std::cout << "j++: " << j++ << std::endl;
    std::cout << "j après j++: " << j << std::endl << std::endl;
    std::cout << "--j: " << --j << std::endl;
    std::cout << "j après --j: " << j << std::endl << std::endl;
    std::cout << "j--: " << j-- << std::endl;
    std::cout << "j après j--: " << j << std::endl << std::endl;
    
    // Test que 1 + epsilon > 1
    std::cout << "\n=== TEST epsilon (1 + epsilon > 1) ===\n";
    Fixed un(1);
    Fixed epsilon = ++Fixed(1) - Fixed(1);
    std::cout << "1 = " << un << std::endl;
    std::cout << "epsilon = " << epsilon << std::endl;
    std::cout << "1 + epsilon = " << (un + epsilon) << std::endl;
    std::cout << "1 + epsilon > 1 ? " << ((un + epsilon) > un) << std::endl;
    
    std::cout << "\n=== TESTS DES FONCTIONS MIN/MAX ===\n";
    Fixed k(3.14f);
    Fixed l(2.71f);
    const Fixed m(5.5f);
    const Fixed n(1.1f);
    
    std::cout << "k = " << k << ", l = " << l << std::endl;
    std::cout << "min(k, l) = " << Fixed::min(k, l) << std::endl;
    std::cout << "max(k, l) = " << Fixed::max(k, l) << std::endl;
    
    std::cout << "\nm = " << m << ", n = " << n << " (const)" << std::endl;
    std::cout << "min(m, n) = " << Fixed::min(m, n) << std::endl;
    std::cout << "max(m, n) = " << Fixed::max(m, n) << std::endl;
    
    std::cout << "\n=== TESTS AVEC NOMBRES NÉGATIFS ===\n";
    Fixed q(-5);
    Fixed r(-2);
    
    std::cout << "q = " << q << ", r = " << r << std::endl;
    std::cout << "q + r = " << (q + r) << std::endl;
    std::cout << "q - r = " << (q - r) << std::endl;
    std::cout << "q * r = " << (q * r) << std::endl;
    std::cout << "q / r = " << (q / r) << std::endl;
    std::cout << "min(q, r) = " << Fixed::min(q, r) << std::endl;
    std::cout << "max(q, r) = " << Fixed::max(q, r) << std::endl;

    
    return 0;
}