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
    map<int,int> g;
    g[0] = 1;
    for(int i = 0; i < n - 1; i++){
        int x; cin >> x;
        g[x]++;
    }
    vector<int> a;
    for(const auto& p : g){
        a.push_back(p.second);
    }
    sort(a.begin(), a.end(), greater<int>());
    int groups = a.size();
    int ans = groups;
    priority_queue<int> mxhp;
    for(int i = 0; i < groups; i++){
        a[i] -= (groups - i);
        mxhp.push(a[i]);
    }
    int buffer = 0;
    while(mxhp.top() > buffer){
        int x = mxhp.top();
        mxhp.pop();
        mxhp.push(x - 1);
        buffer++;
        ans++;
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