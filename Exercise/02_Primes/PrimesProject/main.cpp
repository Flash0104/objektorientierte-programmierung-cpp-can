#include <iostream>

bool is_prime(int number) {
    // Numbers less than 2 are not prime
    if (number < 2) {
        return false;
    }
    
    // Check for divisors from 2 to sqrt(number)
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;  // Found a divisor, not prime
        }
    }
    
    return true;  // No divisors found, it's prime
}

void print_primes(int upper_bound) {
    for(int i = 0; i < upper_bound; i++) {
        if(is_prime(i)) {
            std::cout << i << std::endl;
        }
    }
}

int main()
{

    int maximum_number;

    std::cout << "Please enter a number: ";
    std::cin >> maximum_number;
    std::cout << "Searching all primes until " << maximum_number << std::endl;
    print_primes(maximum_number);
    return 0;
}
