#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

vector<int> primes;

vector<int> sieve(int n){
    vector<int> prime(n+1, 1);
    prime[0] = prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(prime[i]){
            for(long long j = 1LL * i*i; j <= n; j+=i){
            prime[j] = 0;
            }
        }
    }
    vector<int> x;
    for(int i = 0; i <= n; i++){
        if(prime[i]) x.push_back(i);
    }
    return x;
}

bool test_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    map<int,int> seen;
    for(int i = 0; i < n; i++){
        int val = a[i];
        int ind = 0;
        while(ind < primes.size() && val > 1){
            int p = primes[ind];
            if(val % p == 0){
                if(seen[p]) return true;
                seen[p] = 1;
            }
            while(val > 1 && val % p == 0){
                val /= p;
            }
            ind++;
        }
        if(val > 1){
            if(seen[val]) return true;
            seen[val] = 1;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    primes = sieve(sqrt(1e9) + 1);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}