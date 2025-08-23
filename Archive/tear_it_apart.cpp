#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int cost(int dist){
    int ans = 0;
    while(dist > 0){
        if(dist % 2 == 1) dist -= (dist / 2 + 1);
        else dist -= dist / 2;
        ans++;
    }
    return ans;
}

void test_case(){
    string s; cin >> s;
    map<char, vector<int>> locs;
    for(int i = 0; i < s.length(); i++){
        locs[s[i]].push_back(i);
    }
    int ans = 1e9 + 5;
    for(const auto& p : locs){
        vector<int> inds = p.second;
        int max_dist = inds[0];
        for(int i = 1; i < inds.size(); i++){
            max_dist = max(max_dist, inds[i] - inds[i-1] - 1);
        }
        max_dist = max(max_dist, (int) s.size() - inds[inds.size()-1] - 1);
        //debug(p.first, max_dist);
        ans = min(ans, cost(max_dist));
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