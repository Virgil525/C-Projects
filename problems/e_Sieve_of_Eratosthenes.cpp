#include <iostream>
#include <vector>

void SieveOfEratosthenes(int n) {

    std::vector<bool> prime(n+1, true);
    for (int p = 2; p*p <= n; p++){
        if(prime[p]==true){
            for (int i = p*p; i <= n; i+= p)
                prime[i] = false;
        }
    }

    for(int p = 2; p <= n; p++){
        if (prime[p])
            std::cout << p << " ";
    }
}


int main(){
    int n;
    std::cout << "Enter the maximum number: ";
    std::cin >> n;
    std::cout << "Prime numbers up to " << n << " are: ";
    SieveOfEratosthenes(n);
    return 0;
}