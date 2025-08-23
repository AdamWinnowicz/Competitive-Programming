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
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) ans.push_back(-1);
        else{
            if(i == n-1) ans.push_back(2);
            else ans.push_back(3);
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << (i == n-1 ? "\n" : " ");
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