#include <bits/stdc++.h>
using namespace std;

auto pair_sort = [](pair<int,int>& x, pair<int,int>& y){
    return x.first < y.first;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> l(n), r(n);
        vector<pair<int,int>> a;
        long long ans = 0;
        for(int i = 0; i < n; i++) {cin >> l[i]; a.push_back({l[i], i}); ans += l[i];}
        for(int i = 0; i < n; i++) {cin >> r[i]; a.push_back({r[i], i}); ans += r[i];}
        vector<bool> used(n,0);
        sort(a.begin(), a.end(), pair_sort);
        int i = 0, count = 0;
        while(count < n - k + 1){
            int ind = a[i].second;
            if(!used[ind]){
                used[ind] = 1;
                ans -= a[i].first;
                count++;
            }
            i++;
        }
        cout << ans+1 << '\n';

    }

    return 0;
}