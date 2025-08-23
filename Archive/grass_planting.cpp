#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    int n;
    cin >> n;
    
    vector<int> deg(n+1,0);
    int answer = 1;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        deg[a] += 1;
        deg[b] += 1;
        answer = max(answer, deg[a] + 1);
        answer = max(answer, deg[b] + 1);
    }

    cout << answer << '\n';
    return 0;
}