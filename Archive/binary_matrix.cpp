#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){

        int n,m; cin >> n >> m;
        vector<string> matrix;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            matrix.push_back(s);
        }
        int r = 0, c = 0;
        for(int i = 0; i < n; i++){
            int total = 0;
            for(int j = 0; j < m; j++){
                total += matrix[i][j] -'0';
            }
            if(total % 2 == 1) r++;
        }
        for(int j = 0; j < m; j++){
            int total = 0;
            for(int i = 0; i < n; i++){
                total += matrix[i][j] -'0';
            }
            if(total % 2 == 1) c++;
        }
        cout << max(r, c) << '\n';

    }

    return 0;
}