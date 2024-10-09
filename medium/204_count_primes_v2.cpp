#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
    if (n <= 2) return 0; // There are no primes less than 2

    // Create a boolean vector "is_prime" for odd numbers only
    vector<bool> is_prime((n / 2) + 1, true); // Only odd numbers from 3 to n

    int prime_count = 1; // Start with 1 to count '2'

    // Loop through odd numbers starting from 3
    for (int p = 3; p * p < n; p += 2) {
        if (is_prime[p / 2]) { // Check the corresponding index for p
            // Mark all multiples of p as non-prime
            for (int multiple = p * p; multiple < n; multiple += p * 2) {
                is_prime[multiple / 2] = false; // Set corresponding index to false
            }
        }
    }

    // Count the number of primes
    for (int i = 3; i < n; i += 2) {
        if (is_prime[i / 2]) {
            prime_count++;
        }
    }

    return prime_count; // Return the count of prime numbers
}

int main() {
    int n;
    cout << "Enter the upper limit (n): ";
    cin >> n;

    int prime_count = countPrimes(n);
    cout << "Number of prime numbers up to " << n << ": " << prime_count << endl;

    return 0;
}
