// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int p; cin >> p;
    set<int> have;
    for(int i = 0; i < p; i++){
        int x; cin >> x;
        have.insert(x);
    }
    cin >> p;
    for(int i = 0; i < p; i++){
        int x; cin >> x;
        have.insert(x);
    }
    cout << (have.size() == n ? "I become the guy.\n" : "Oh, my keyboard!\n");
}
