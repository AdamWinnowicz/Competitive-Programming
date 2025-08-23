#include <iostream>
#include "bits/stdc++.h"
using namespace std;

const int N = 1000000;
#define SIEVE
vector<int> prime(N+1, 1);

void sieve(){
    prime[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            for (long long j = 1LL * i*i; j <= N; j += i){
                prime[j] = 0;
            }
        }
    }
}

int main() {
    sieve();
    for (int i = 1; i <= N; i++) {
        if (prime[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}