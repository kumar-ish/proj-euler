#include<iostream>  
  
using namespace std; 

int fib(int n) {
    long long sum = 0;
    int first = 1;
    int second = 2;
    int temp;
    while (second <= n) {
        if (second % 2 == 0) {
	    sum = sum + second;
	}
	temp = first + second;
	first = second;
	second = temp;
	// cout << second << "\n";
    }
    return sum;    
}

int main() 
{  
    cout << fib(40000000) << "\n";
    return 0; 
} 

