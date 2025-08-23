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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    string ans;
    int l = 0, r = n-1;
    int turn = 1;
    while(l < r){
        if(turn % 2 == 1){
            if(a[l] < a[r]){
                ans += "L";
                l++;
            }
            else{
                ans += "R";
                r--;
            }
        }
        else{
            if(a[l] > a[r]){
                ans += "L";
                l++;
            }
            else{
                ans += "R";
                r--;
            }
        }
        turn++;
    }
    ans += "L";
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