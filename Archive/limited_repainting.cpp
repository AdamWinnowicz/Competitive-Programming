#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> a(n);
        int r = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            r = max(r, a[i]);
        }
        int l = 0;
        while(l < r){
            int m = l + (r - l) / 2; // check if we can make the penalty no more than m (k steps)
            string new_s;            // if it is possible, range = [l, m] else range = [m+1, r]
            for(int i = 0; i < n; i++){
                if(a[i] > m) new_s += s[i];
            }
            string segment = ""; segment += new_s[0];
            int blue_count = 0;
            for(int i = 1; i < new_s.length(); i++){
                if(new_s[i] == segment[0]) segment += new_s[i];
                else{
                    if(segment[0] == 'B') blue_count++;
                    segment = ""; segment += new_s[i];
                }
            }
            if(segment[0] == 'B') blue_count++;
            if(blue_count <= k) r = m;
            else l = m+1;
        }
        cout << l << '\n';
    }

    return 0;
}