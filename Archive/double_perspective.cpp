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
    vector<tuple<int,int,int>> segs;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        segs.push_back({l, r, i + 1});
    }
    sort(segs.begin(), segs.end(), [](tuple<int,int,int> a, tuple<int,int,int> b){
        if(get<0>(a) == get<0>(b)){
            return get<1>(a) > get<1>(b);
        }
        else return get<0>(a) < get<0>(b);
    });
    vector<int> ans;
    int prev = -1;
    for(tuple<int,int,int> info : segs){
        if(get<0>(info) != prev){
            ans.push_back(get<2>(info));
            prev = get<0>(info);
        }
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << (i == ans.size() -1 ? "\n" : " ");
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