#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    string ans = "";
    vector<pair<int,int>> c;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        c.emplace_back(x, y);
    }
    sort(c.begin(), c.end());
    int cx = 0, cy = 0;
    bool possible = true;
    for(int i = 0; i < n; i++){
        pair<int,int> p = c[i];
        int x = p.first, y = p.second;
        if(y < cy){
            possible = false; break;
        }
        for(int j = cx; j < x; j++){
            ans += 'R';
        }
        for(int j = cy; j < y; j++){
            ans += 'U';
        }
        cx = x; cy = y;
    }
    if(possible){
        cout << "YES\n";
        cout << ans << '\n';
    }
    else{
        cout << "NO\n";
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