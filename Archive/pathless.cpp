#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, s; cin >> n >> s;
    vector<int> a(n);
    int sum = 0;
    int z = 0, o = 0, t = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        if(a[i] == 0) z++;
        else if(a[i] == 1) o++;
        else if(a[i] == 2) t++;
    }
    if(sum > s){
        for(int i = 0; i < n; i++){
            cout << a[i] << (i == n-1 ? "\n" : " ");
        }
    }
    else if(sum == s){
        cout << -1 << '\n';
    }
    else{
        int diff = s - sum;
        if(diff % 2 == 0 || diff % 3 == 0){
            cout << -1 << '\n'; return;
        }
        int d = diff;
        while(d >= 3){
            if(d % 2 == 0){
                cout << -1 << '\n'; return;
            }
            d -= 3;
        }
        d = diff;
        while(d >= 2){
            if(d % 3 == 0){
                cout << -1 << '\n'; return;
            }
            d -= 2;
        }
        vector<int> ans;
        for(int i = 0; i < z; i++) ans.push_back(0);
        for(int i = 0; i < t; i++) ans.push_back(2);
        for(int i = 0; i < o; i++) ans.push_back(1);
        for(int i = 0; i < n; i++){
            cout << ans[i] << (i == n-1 ? "\n" : " ");
        }
    }
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