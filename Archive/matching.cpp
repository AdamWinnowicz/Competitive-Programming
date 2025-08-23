#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        unordered_map<int,vector<int>> connected;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            connected[i - a].push_back(a);
        }
        long long ans = 0;
        for(const auto& p : connected){
            vector<int> vals = p.second;
            if(vals.size() >= 2){
                sort(vals.begin(), vals.end(), greater<int>());
                for(int i = 0; i < vals.size()-1; i+= 2){
                    int total = vals[i] + vals[i+1];
                    ans += max(total,0);
                }
            }
        }
        cout << ans << '\n';
 
    }
 
    return 0;
}