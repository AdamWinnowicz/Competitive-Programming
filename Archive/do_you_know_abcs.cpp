#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v;
    for(int i = 0; i < 7; i++){
        int val;
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(),v.end());
    int a = v[0], b = v[1], c;
    c = v[6] - a - b;
    cout << a << " " << b << " " << c << '\n';
    return 0;
}