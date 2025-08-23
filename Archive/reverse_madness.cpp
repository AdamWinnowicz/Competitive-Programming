#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> l(k), r(k);
    for(int i = 0; i < k; i++) cin >> l[i];
    for(int i = 0; i < k; i++) cin >> r[i];
    int q; cin >> q;
    map<int,int> swaps;
    for(int i = 0; i < q; i++){
        int x; cin >> x;
        auto it = upper_bound(r.begin(), r.end(), x-1);
        int ind = it - r.begin();
        int L = l[ind], R = r[ind];
        int a = min(x, R + L - x), b = max(x, R + L - x);
        swaps[a-1]++;
    }
    for(int i = 0; i < k; i++){
        int L = l[i], R = r[i], end = L + (R - L) / 2;
        L--; R--; end--;
        bool on = false;
        for(int x = L; x <= end; x++){
            if(swaps[x] % 2 == 1){
                on = !on;
            }
            if(on){
                swap(s[x], s[R - (x - L)]);
            }
        }
    }
    cout << s << '\n';
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