#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<string, int>> v;

    for (int i = 0; i < n; i++) {
        string s;
        int score;
        cin >> s;
        cin >> score;
        v.emplace_back(s,score);
    }

    sort(v.begin(),v.end(), [](const pair<string,int>& a, const pair<string, int>& b) {
        if (a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    for (auto& p : v){
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}