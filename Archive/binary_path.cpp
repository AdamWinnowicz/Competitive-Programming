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
    vector<string> a(2);
    cin >> a[0] >> a[1];
    string best;
    int i = 0, j = 0;
    while(j < n){
        best += a[i][j];
        if(i == 0 && (j == n-1 || a[i][j+1] > a[i+1][j])){
            i++;
        }
        else j++;
    }
    cout << best << '\n';
    int last_ind = n - 1, first_ind = 0;
    for(int i = 0; i < n; i++){
        if(a[0][i] != best[i]){
            last_ind = i - 1; break;
        }
    }
    for(int i = n-1; i > -1; i--){
        if(a[1][i] != best[i+1]){
            first_ind = i + 1; break;
        }
    }
    cout << last_ind - first_ind + 1 << '\n';
    
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