#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> sieve(int n){
   vector<ll> prime(n+1, 1);
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
vector<ll> prime = sieve(6000000);
vector<ll> prime_sum(500000);

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    ll total = 0;
    ll length = 0;
    while(length < n){
        total += a[length];
        if(total >= prime_sum[length+1]){
            length++;
        }
        else break;
    }
    cout << n - length << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll prime_count = 0, sum = 0;
    for(int i = 2; i < 6000000; i++){
        if(prime[i]){
            prime_count++;
            sum += i;
            prime_sum[prime_count] = sum;
        }
    }
    //cout << prime_sum[1] << " " << prime_sum[2] << " " << prime_sum[3] << '\n';
    int t; cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}