#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
void test_case(){
    ll n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n-1;
    int ans = 0;
    bool onl = true;
    while(l < r){
        int smaller = min(a[l], a[r]);
        bool used = false;
        if(onl){
            if((a[l] <= a[r] && 2 * smaller - 1 > k) || (a[l] > a[r] && 2 * smaller > k)) break;
            if(a[l] <= a[r]){
                a[l] -= smaller; a[r] -= (smaller - 1); l++; k -= (2 * smaller - 1); ans++; onl = false;
            }
            else{
                a[l] -= smaller; a[r] -= smaller; r--; k -= 2 * smaller; ans++; onl = true;
            }
        }
        else{
            if((a[l] < a[r] && 2 * smaller > k) || (a[l] >= a[r] && (2 * smaller - 1) > k)) break;
            if(a[l] < a[r]){
                a[l] -= smaller; a[r] -= smaller; l++; k -= 2 * smaller; ans++; onl = false;
            }
            else{
                a[l] -= (smaller - 1); a[r] -= smaller; r--; k -= (2 * smaller - 1); ans++; onl = true;
            }
        }
    }
    if(l == r){
        if(a[l] > 0 && k >= a[l]) ans++;
    }
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case() ? "Yes\n" : "No\n");
    }
 
    return 0;
}