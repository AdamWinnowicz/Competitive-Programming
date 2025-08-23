#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> sieve(int n){
   vector<int> prime(n+1, 1);
   prime[0] = prime[1] = false;
   for(int i = 2; i <= n; i++){
      if(prime[i]){
         for(long long  j = 1LL * i*i; j <= n; j+=i){
            prime[j] = 0;
         }
      }
   }
   return prime;
}

vector<int> prime = sieve(1e7);

void test_case(){
    int n; cin >> n;
    int total = 0;
    for(int i = 2; i <= n; i++){
        if(prime[i]) total += n / i;
    }
    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}