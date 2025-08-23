#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, m; cin >> n >> m;
    vector<multiset<int>> g;
    map<int, set<pair<int,int>>> loc;
    vector<int> l;
    for(int i = 0; i < n; i++){
        multiset<int> r;
        for(int j = 0; j < m; j++){
            int length; cin >> length;
            loc[length].insert({i, j});
            l.push_back(length);
            r.insert(length);
        }
        g.push_back(r);
    }
    vector<vector<int>> ans(n, vector<int>(m, 0));
    sort(l.begin(), l.end());
    for(int k = 0; k < m; k++){
        int length = l[k];
        pair<int,int> p = *loc[length].begin();
        int i = p.first,  j = p.second;
        ans[i][k] = length;
        loc[length].erase({i, j});
        g[i].erase(g[i].find(length));
    }
    for(int i = 0; i < n; i++){
        multiset<int> lengths = g[i];
        for(int j = 0; j < m; j++){
            if(ans[i][j] == 0){
                ans[i][j] = *lengths.begin();
                lengths.erase(lengths.find(ans[i][j]));
            }
            cout << ans[i][j] << (j == m-1 ? "\n" : " ");
        }
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