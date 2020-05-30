#include<iostream>  
#include<cmath>
#include<vector>

using namespace std; 

long long sum_primes(int n) {
    const unsigned int SIZE = ceil(n * (log(n) + log(log(n)))); // upper bound for nth prime
    std::vector<bool> is_prime(SIZE);

    // Sieve of Greek-something algo from memory
    is_prime[2] = is_prime[3] = true;
    for (int i = 4; i < SIZE; i++) {
        is_prime[i] = true;
    }
    
    for (int i = 2; i < ceil(sqrt(SIZE)); i++) {
        if (is_prime[i]) {
	    for (int num = i * i; num < SIZE; num += i) {
	        is_prime[num] = false;
	    }
	}
    }
    long long sum = 0;
    for (int i = 2; i < SIZE; i++) {
	//cout << is_prime[i] << " ";
	if (is_prime[i]) {
	    // cout << sum << " ";
	    if (i > n) {
	        return sum;
	    }	    
	    sum += i;
	    //cout << i << " " << count << "\n"; 
	}
    }
    return 0;
}

int main() 
{ 
    cout << sum_primes(2000000) << "\n";
    return 0; 
} 
