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
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> first_diff(n);

    int i = 0;
    int last_j = -1;
    while(i < n){
        if(last_j > i){
            first_diff[i] = last_j;
        }
        else{
            int j = i + 1;
            while(j < n && a[j] == a[i]){
                j++;
            }
            first_diff[i] = j;
            last_j = j;
        }
        i++;
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r; l--; r--;
        int best_r = first_diff[l];
        if(best_r <= r){
            cout << l+1 << " " << best_r+1 << '\n';
        }
        else{
            cout << -1 << " " << -1 << '\n';
        }
    }
    cout << '\n';
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