#include <bits/stdc++.h>
using namespace std;

int dx(int start, int end, int length){
    int godirectly = abs(end-start);
    int wraparound = length - godirectly;
    return min(godirectly, wraparound);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int x = 0; x < t; x++){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> locations(n*m+1, {0,0});
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int val;
                cin >> val;
                locations[val] = {i,j};
            }
        }
        int totaldistance = 0;
        int curri = 0, currj = 0;
        for(int target = 1; target <= m*n; target++){
            pair<int,int> p = locations[target];
            int ni = p.first, nj = p.second;
            int dist = dx(curri,ni,n) + dx(currj,nj,m);
            totaldistance += dist;
            curri = ni;
            currj = nj;
        }
        cout << totaldistance << '\n';
    }
    return 0;
}