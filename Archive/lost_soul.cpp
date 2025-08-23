#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    set<int> even_a_odd_b, odd_a_even_b;
    set<int> prev, any;
    int x = 1;
    int ans = 0;
    while(n-x > -1){
        if(a[n-x] == b[n-x] || any.find(a[n-x]) != any.end() || any.find(b[n-x]) != any.end()){
            ans = n - x + 1; break;
        }
        if(x % 2 == 1){
            if(even_a_odd_b.find(a[n-x]) != even_a_odd_b.end() || odd_a_even_b.find(b[n-x]) != odd_a_even_b.end()){
                ans = n - x + 1; break;
            }
            odd_a_even_b.insert(a[n-x]);
            even_a_odd_b.insert(b[n-x]);
        }
        else{
            if(odd_a_even_b.find(a[n-x]) != odd_a_even_b.end() || even_a_odd_b.find(b[n-x]) != even_a_odd_b.end()){
                ans = n - x + 1; break;
            }
            odd_a_even_b.insert(b[n-x]);
            even_a_odd_b.insert(a[n-x]);
        }
        if(!prev.empty()){
            for(int val : prev){
                any.insert(val);
            }
            prev.clear();
        }
        prev.insert(a[n-x]); prev.insert(b[n-x]);
        x++;
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