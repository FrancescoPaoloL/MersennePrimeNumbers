#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdint.h>

#define UPPER_LIMIT 1000000 // Define the upper limit for prime searching

/*
    Trial Division: The algorithm checks divisibility by small primes (2 and 3) and then checks divisibility by numbers of the form 6k ± 1, a common technique in trial division.

    Sieve of Eratosthenes: While not directly implementing the Sieve of Eratosthenes, the algorithm's approach of eliminating multiples of 2 and 3 is reminiscent of this ancient prime sieving method.

    Primality Tests: Although not as sophisticated as probabilistic or deterministic primality tests like Miller-Rabin or AKS primality test, respectively, the algorithm's approach shares similarities with simpler primality tests by performing divisibility checks.
*/


bool is_prime(uint64_t n) {
    // No zero or negative numbers are prime
    if (n <= 1) return false;
    // two and three are prime
    if (n <= 3) return true;
    // even numbers and multiple of three are not prime
    if (n % 2 == 0 || n % 3 == 0) return false;

    // All prime numbers can be written in the form of "6k ± 1"
    // Then:
    //  "i"     represents numbers of the form "6k - 1"
    //  "i + 2" represents numbers of the form "6k + 1"
    for (uint64_t i = 5; i * i <= n; i += 6) {
        // If 'n' is divisible by any of thee numbers, it's not prime
        // then it indicates that 'n' has at least three distinct positive 
        // divisors (1, the divisor, and n itself).
        // By definition, prime numbers have only two distinct positive divisors, so...
        // it's not prime!
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Here we use the Lucas–Lehmer test (LLT) 
// that is a primality test for Mersenne numbers 
// determining if a given number p is "a prime exponent".
// In other words, it's verifying if p can be written as an exponent in the expression 2^p, where p is a prime number.
// For example:
//    If p is 2, then 2 is a prime exponent because 2 can be written as 2^2.
//    If p is 3, then 3 is a prime exponent because 3 can be written as 2^3.
//    If p is 4, then it's not a prime exponent because 4 can be written as 2^2, but 2 is not a prime number.
bool is_prime_exponent(uint64_t p) {
    if (p == 2) return true; // Special case for p = 2
    uint64_t s = 4;
    // Use Lucas-Lehmer primality test for Mersenne primes
    // 1ULL to ensure that the number 1 is treated as an unsigned long long integer (bit manipulation operations)
    for (uint64_t i = 3; i <= p; i++) {
        s = (s * s - 2) % ((1ULL << p) - 1);
    }
    return s == 0; // If s equals 0, 2^p - 1 is prime
}

void find_mersenne_primes(int upb, FILE *output_file) {
    for (int p = 2; p <= upb; p++) {
        if (is_prime(p) && is_prime_exponent(p)) {
            fprintf(output_file, "%d ", p);
        }
    }
}

int main() {
    clock_t t1;
    t1 = clock();

    FILE *output_file;
    output_file = fopen("mersenne_primes.txt", "w");
    if (output_file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("Finding Mersenne primes...\n");
    find_mersenne_primes(UPPER_LIMIT, output_file);
    printf("Mersenne primes found and saved to 'mersenne_primes.txt'.\n");

    fclose(output_file);

    printf("Time elapsed: %.2f seconds\n", (double)(clock() - t1) / CLOCKS_PER_SEC);
    return 0;
}
