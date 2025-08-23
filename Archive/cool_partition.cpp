#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = 1;
        set<int> needed, found, next_needed;
        needed.insert(a[0]);
        vector<int> curr;
        for(int i = 1; i < n; i++){
            curr.push_back(a[i]); next_needed.insert(a[i]);
            if(needed.find(a[i]) != needed.end()){
                found.insert(a[i]);
            }
            if(found.size() == needed.size()){
                ans++;
                needed = next_needed;
                found.clear();
                next_needed.clear();
            }
        }
        cout << ans << '\n';
    }

    return 0;
}