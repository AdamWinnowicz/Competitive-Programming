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
    vector<vector<int>> a;
    for(int i = 0; i < n; i++){
        vector<int> val(2);
        cin >> val[0] >> val[1];
        a.push_back(val);
    }
    sort(a.begin(), a.end(), [](vector<int> x, vector<int> y){
        return (x[0] + x[1]) < (y[0] + y[1]);
    });
    vector<int> ans;
    for(int i = 0; i < n; i++){
        vector<int> line = a[i];
        ans.push_back(line[0]); ans.push_back(line[1]);
    }
    for(int i = 0; i < 2*n; i++){
        cout << ans[i] << (i == 2*n-1 ? "\n" : " ");
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