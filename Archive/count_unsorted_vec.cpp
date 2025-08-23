#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        v.push_back(val);
    }

    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++){
        int x;
        cin >> x;
        cout << count(v.begin(),v.end(),x) << '\n';
    }

    return 0;
}