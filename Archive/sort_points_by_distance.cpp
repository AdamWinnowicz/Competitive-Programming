#include <bits/stdc++.h>
using namespace std;

auto Distance = [](const pair<int,int>& p){
    return p.first * p.second + p.second * p.second;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.emplace_back(x,y);
    }

    sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        if (Distance(a) == Distance(b)){
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        }
        return Distance(a) < Distance(b);
    });

    for(auto&p : v){
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}