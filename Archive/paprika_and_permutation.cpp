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
    vector<int> a;
    set<int> already;
    for(int i = 0; i < n; i++){
        int b; cin >> b;
        if(already.find(b) != already.end()){
            a.push_back(b);
        }
        if(b <= n) already.insert(b);
        else a.push_back(b);
    }
    sort(a.begin(), a.end());
    vector<int> upper_bound;
    for(int i = 0; i < a.size(); i++){
        upper_bound.push_back((a[i] - 1) / 2);
    }

    bool possible = true;
    int ind = 0;
    for(int i = 1; i <= n; i++){
        if(already.find(i) != already.end()) continue;
        if(i > upper_bound[ind]){
            possible = false; break;
        }
        ind++;
    }
    if(!possible){
        cout << -1 << '\n';
    }
    else{
        cout << a.size() << '\n';
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