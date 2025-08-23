#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> bit_count(31, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int b = 0; b < 31; b++){
            if((1LL << b) & a[i]){
                bit_count[b]++;
            }
        }
    }
    ll ans = 0;
    for(int k = 0; k < n; k++){
        ll total = 0;
        for(int b = 0; b < 31; b++){
            if((1 << b) & a[k]){
                int are_zero = n - bit_count[b];
                total += are_zero * (1LL << b);
            }
            else{
                total += bit_count[b] * (1LL << b);
            }
        }
        ans = max(ans, total);
    }
    cout << ans << '\n';

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