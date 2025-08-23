#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    vector<pair<double, int>> info;
    for(int i = 0; i < n; i++){
        int x, y, k; cin >> x >> y >> k;
        double d = sqrt(x*x + y*y);
        info.push_back({d, k});
    }
    sort(info.begin(), info.end());
    double radius = 0.0;
    for(int i = 0; i < n; i++){
        if(s >= 1e6) break;
        pair<double, int> x = info[i];
        double d = x.first;
        int k = x.second;
        s += k;
        radius = d;
    }
    if(s >= 1e6){
        cout << fixed << setprecision(7) << radius << '\n';
    }
    else{
        cout << -1 << '\n';
    }
    

    return 0;
}