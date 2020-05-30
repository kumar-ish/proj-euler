#include<iostream>  
#include<climits>
#include<cmath>
#include<vector>

using namespace std; 

int nth_prime(int n) {
    const unsigned int SIZE = ceil(n * (log(n) + log(log(n)))); // upper bound for nth prime
    std::vector<bool> is_prime(SIZE);

    // Sieve of Greek-something algo from memory
    is_prime[2] = is_prime[3] = true;
    for (int i = 4; i < SIZE; i++) {
        is_prime[i] = true;
    }
    
    for (int i = 2; i < SIZE; i++) {
        if (is_prime[i]) {
	    for (int num = i * i; num < SIZE; num += i) {
	        is_prime[num] = false;
	    
	        //cout << num << "\n";
	        //if (i % 10000 == 0) {
	        //    cout << i << "\n";
	        //}
	    }
	}
    }
    int count = 0;
    for (int i = 2; i < SIZE; i++) {
	//cout << is_prime[i] << " ";
	if (is_prime[i]) {
	    count++;
	    //cout << i << " " << count << "\n"; 
	    if (count == n) {
	        return i;
	    }
	}
    }
    return 0;
}

int main() 
{ 
    cout << nth_prime(10001) << "\n";
    return 0; 
} 
