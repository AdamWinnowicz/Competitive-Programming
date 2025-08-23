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
    if(a[n-1] == 1){
        cout << "NO\n"; return;
    }
    vector<int> ans;
    vector<int> st;
    int used_zeros = 0;
    for(int i = 0; i < n; i++){
        debug(used_zeros, ans, st);
        if(a[i] == 1) st.push_back(i);
        else{
            ans.push_back(i - used_zeros);
            if(st.size() > 0){
                for(int j = 0; j < st.size(); j++){
                    ans.push_back(st[j] - used_zeros); used_zeros++;
                }
                st.clear();
            }
            used_zeros++;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        cout << ans[n-i-1] << (i == n-1 ? "\n" : " ");
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