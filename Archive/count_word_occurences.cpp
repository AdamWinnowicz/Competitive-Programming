#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<string, int> m;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        m[s]++;
    }

    for (const auto& pair : m) {
        cout << pair.first << " " << pair.second << '\n';
    }

    return 0;
}