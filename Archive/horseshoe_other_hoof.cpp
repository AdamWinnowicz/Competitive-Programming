#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<int> v;
    for(int i = 0; i < 4; i++){
        int a; cin >> a;
        v.insert(a);
    }
    cout << 4 - v.size() << '\n';


    return 0;
}