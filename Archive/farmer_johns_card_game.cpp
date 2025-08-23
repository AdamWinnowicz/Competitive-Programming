#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> info;
        for(int i = 0; i < n; i++){
            vector<int> cards;
            for(int j = 0; j < m; j++){
                int val; cin >> val;
                cards.push_back(val);
            }
            sort(cards.begin(), cards.end());
            cards.push_back(i+1);
            info.push_back(cards);
        }
        sort(info.begin(), info.end());
        vector<int> pile = {-1};
        bool possible = true;
        for(int j = 0; j < m; j++){
            if(!possible) break;
            for(int i = 0; i < n; i++){
                if(info[i][j] > pile.back()){
                    pile.push_back(info[i][j]);
                }
                else{
                    possible = false;
                    break;
                }
            }
        }
        if(!possible) cout << -1 << '\n';
        else{
            for(int i = 0; i < n; i++){
                cout << info[i][m] << (i == n-1 ? "\n" : " ");
            }
        }

    }

    return 0;
}