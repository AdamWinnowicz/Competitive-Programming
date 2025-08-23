#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool test_case(){
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    int movable = max(n-k, 0);

    for(int i = movable; i < n - movable; i++){
        if(s[i] != t[i]) return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}