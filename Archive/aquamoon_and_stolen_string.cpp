#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, m; cin >> n >> m;
    vector<string> a(n), b(n-1);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n-1; i++) cin >> b[i];
    string ans;
    for(int j = 0; j < m; j++){
        multiset<char> e;
        for(int i = 0; i < n; i++){
            e.insert(a[i][j]);
        }
        for(int i = 0; i < n-1; i++){
            e.erase(e.find(b[i][j]));
        }
        ans += *e.begin();
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