#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

bool test_case(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int m; cin >> m;
    map<int,int> cnt; int last = -1;
    for(int i = 0; i < m; i++){
        int d; cin >> d;
        cnt[d]++;
        if(i == m-1) last = d;
    }
    if(find(b.begin(), b.end(), last) == b.end()) return false;
    vector<int> needed;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            needed.push_back(b[i]);
        }
    }
    for(int i = 0; i < needed.size(); i++){
        if(cnt[needed[i]] > 0) cnt[needed[i]]--;
        else return false;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}