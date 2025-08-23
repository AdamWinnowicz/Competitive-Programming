// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
    array of size n

    integer e

    calculate number of pairs i, k (positive ints)

    and product of elements in a starting from i and ending at e*k with jumps of e is prime

    this means that i + e*k must be <= n

    How can a product of numbers be prime?

    Only if one element is a prime and all the rest are 1s

    Problem is only really defined by jumps of length e

    wherever there is a prime number we can do it 

    if the number is prime we can look to the left and the right and if there are ones we can increase the length

    once we have a length that works (the maximum we can do) the length on the left times the length on the right

    if we check this for every prime, we could end up with close to o(n**2) in worst case

    we can probably do it faster by looking at ones instead

    question is

    for each index, how many indexes can we end at such that there is one prime in the subsequence and all others are ones

    If we have another 1, we can add it onto any sequence that already works

    If we have another prime, we can add it onto any sequence of ones that we already have

    lets use dp to keep track of the number of sequences that work and the number of sequences of ones

    Also nice thing for dp is the fact that the jump is always by e so we can just look back at previous sequences that are e before

    dp[i] = the number of good sequences that end at i

    dp2[i] = the number of sequences of ones that end at i

    if a[i] == 1: dp[i] = dp[i-e] (add one if the last one is prime), dp2[i] = dp2[i-e] + 1
    if a[i] == prime: dp[i] = dp2[i-e], dp2[i] = 0;
*/

vector<bool> prime(1e6 + 1, true);

void solve(){
    int n, e; cin >> n >> e;
    vector<int> a(n);
    for(int & x : a) cin >> x;
    vector<int> dp(n), dp2(n);
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            if(i - e > -1){
                dp[i] = dp[i-e] + (prime[a[i-e]] == true);
                dp2[i] = dp2[i-e] + 1;
            }
            else dp2[i] = 1;
        }
        if(prime[a[i]]){
            if(i - e > -1){
                dp[i] = dp2[i-e];
            }
            dp2[i] = 0;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += dp[i];
        // cout << dp[i] << " ";
    }
    // cout << '\n';
    // for(int i = 0; i < n; i++){
    //     cout << dp2[i] << " ";
    // }
    // cout << '\n';
    cout << ans << '\n';

}

int main() {

    prime[0] = prime[1] = false;
    for(ll i = 2; i <= 1e6; i++){
        if(prime[i]){
            for(ll j = i * i; j <= 1e6; j += i){
                prime[j] = false;
            }
        }
        
    }

	int t; cin >> t;
    while(t--){
        solve();
    }
}
