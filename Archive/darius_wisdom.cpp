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
    set<int> ones, zeros;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1){
            ones.insert(i);
        }
        else if(a[i] == 0){
            zeros.insert(i);
        }
    }
    vector<pair<int,int>> ops;
    int m = zeros.size();
    for(int i = 0; i < m; i++){
        if(a[i] == 2){
            int last_one = *prev(ones.end());
            if(last_one > i){
                ops.push_back({i, last_one});
                ones.erase(*prev(ones.end()));
                swap(a[i], a[last_one]);
                
            }
        }
        if(a[i] == 1){
            int last_zero = *prev(zeros.end());
            if(last_zero > i){
                ops.push_back({i, last_zero});
                zeros.erase(*prev(zeros.end()));
                swap(a[i], a[last_zero]);
                ones.insert(last_zero);
            }
        }
    }
    int z = ones.size();
    for(int i = m; i < m + z; i++){
        if(a[i] == 2){
            int last_one = *prev(ones.end());
            if(last_one > i){
                ops.push_back({i, last_one});
                ones.erase(*prev(ones.end()));
                swap(a[i], a[last_one]);
                
            }
        }
    }
    cout << ops.size() << '\n';
    for(pair<int,int> x : ops){
        cout << x.first + 1 << " " << x.second + 1 << '\n';
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