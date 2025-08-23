#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];
    string ans;
    map<int,int> counter;
    map<int,int> cnt;
    int curr_set = 1;
    for(int i = 0; i < m; i++){
        cnt[a[i]]++;
        counter[cnt[a[i]]]++;
        if(counter[curr_set] == n){
            ans += '1'; curr_set++;
        }
        else ans += '0';
    }
    cout << ans << '\n';

    return 0;
}