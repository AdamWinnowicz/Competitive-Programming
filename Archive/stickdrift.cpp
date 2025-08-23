#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int len = s.length();
        map<int, pair<int,int>> d;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x; cin >> x;
                d[x] = {i,j};
            }
        }
        long long ans = 0;
        int currx = 0, curry = 0, idx = 0;

        for(auto& z : d){
            pair<int,int> p = z.second;
            int x = p.first, y = p.second;
            #define dist() (min(abs(currx - x), n - abs(currx - x)) + min(abs(curry - y), m - abs(curry - y)))
            int moves = 0;
            while (dist() > moves){
                if (s[idx] == 'U') currx = (currx + n - 1) % n;
                else if (s[idx] == 'D') currx = (currx + 1) % n;
                else if (s[idx] == 'L') curry = (curry + m - 1) % m;
                else if (s[idx] == 'R') curry = (curry + 1) % m;
                idx = (idx + 1) % len;
                ++moves;
            }
            ans += moves;
            currx = x;
            curry = y;
        }
        cout << ans << '\n';
    }
    return 0;
}