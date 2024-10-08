using namespace std;
#include <iostream>
#include <vector>

int countPrimes(int n) {

    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < n; i++) {
        if (is_prime[i] && (long long)i * i < n) {
            for (int j = i * i; j < n; j += i)
                is_prime[j] = false;
        }
    }

    // Count the number of primes
    int prime_count = 0;
    for (int i = 2; i < n; i += 1) {
        if (is_prime[i]) {
            prime_count++;
        }
    }
    return prime_count; // Return the count of prime numbers
}

int main() {
    int a;
    cout << "Enter the upper limit (n): ";
    cin >> a;

    int prime_count = countPrimes(a);
    cout << "Number of prime numbers up to " << a << ": " << prime_count << endl;

    return 0;
}
