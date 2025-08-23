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
    map<int,int> cnt;
    vector<set<int>> bits;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        set<int> b;
        for(int j = 0; j < k; j++){
            int bit; cin >> bit;
            b.insert(bit);
            cnt[bit]++;
        }
        bits.push_back(b);
    }
    bool possible = false;
    for(int i = 0; i < n; i++){
        bool found = true;
        set<int> b = bits[i];
        for(int bit : b){
            if(cnt[bit] == 1){
                found = false; break;
            }
        }
        if(found){
            possible = true; break;
        }
    }
    return possible;

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