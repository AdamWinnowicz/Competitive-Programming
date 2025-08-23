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
    vector<vector<int>> locs(n + 1);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        locs[x].push_back(i);
    }
    vector<int> a(n), b(n);
    queue<pair<int,int>> st;
    for(int v = n; v > 0; v--){
        vector<int> lo = locs[v];
        if(lo.size() == 0 && st.empty()){
            cout << "NO\n"; return;
        }
        else if(lo.size() == 0){
            pair<int,int> c = st.front();
            int l1 = c.first, l2 = c.second;
            b[l1] = v; a[l2] = v;
            st.pop();
        }
        else if(lo.size() == 1){
            a[lo[0]] = v; b[lo[0]] = v;
        }
        else if(lo.size() == 2){
            a[lo[0]] = v; b[lo[1]] = v;
            st.push({lo[0], lo[1]});
        }
        else{
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) cout << a[i] << (i == n-1 ? "\n" : " ");
    for(int i = 0; i < n; i++) cout << b[i] << (i == n-1 ? "\n" : " ");
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