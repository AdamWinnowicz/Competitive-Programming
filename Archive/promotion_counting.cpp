#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    vector<pair<int,int>> div;
    for(int i = 0; i < 4; ++i){
        int start, end;
        cin >> start >> end;
        div.emplace_back(start,end);
    }
    int s, g, p;
    p = div[3].second - div[3].first;
    g = (div[2].second + p) - div[2].first;
    s = (div[1].second + g) - div[1].first;

    cout << s << '\n';
    cout << g << '\n';
    cout << p << '\n';

    return 0;
}