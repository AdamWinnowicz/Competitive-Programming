#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        string s; cin >> s;
        vector<vector<ll>> a(n, vector<ll>(m));
        for(int i = 0; i < n; i++){
            vector<ll> row(m);
            for(int j = 0; j < m; j++) cin >> row[j];
            a[i] = row;
        }
        int i = 0, j = 0;
        for(int ind = 0; ind < n + m - 2; ind++){
            char dir = s[ind];
            ll sum = 0;
            if(dir == 'D'){
                for(int nj = 0; nj < m; nj++){
                    sum += a[i][nj];
                }
                a[i][j] = -1 * sum;
                i++;
            }
            else{
                for(int ni = 0; ni < n; ni++){
                    sum += a[ni][j];
                }
                a[i][j] = -1 * sum;
                j++;
            }
        }
        ll sum = 0;
        for(int j = 0; j < m; j++){
            sum += a[n-1][j];
        }
        a[n-1][m-1] = -1 * sum;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << a[i][j] << (j == m-1 ? "\n" : " ");
            }
        }

    }

    return 0;
}