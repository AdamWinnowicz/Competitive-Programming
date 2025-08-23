#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        set<int> a;
        for(int i = 0; i < n; i++){
            int val; cin >> val;
            a.insert(val);
        }
        cout << a.size() << '\n';

    }

    return 0;
}