// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
/*
    let's call the balance of a row or column the difference between the number of black and white colorings needed

    one thing we know about dominos is that if it covers two squares and one needs to be a certain color to be valid, the other square has to add the opposite color
    
    also, if we add a domino from left to right or up to down, this never affects the direction it is going (row or col)

    this is because it always adds one black and one white

    however we know it decreases the balance of the opposite direction two cols or two rows

    if any number of cells covered by dominos in a row is odd, return -1

    otherwise it seems like we can always color the dominos properly

    this is because if there are an even number of dominos that share two rows we can make half one type an half the other type

    this works perfectly because dominos can only cover two rows or columns at once

    how can we do this algorithmically?

    first we can paint all the sideways dominos

    traverse the columns and look for "L"

    in that case paint half in the row to be "BW" and the other half to be "WB"

    if we ever can't paint half because the number of "L" is odd, return -1 right away

    then we can do the same with all the upright dominos

*/
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        string a; cin >> a;
        for(int j = 0; j < m; j++){
            grid[i][j] = a[j];
        }
    }
    for(int j = 0; j < m; j++){
        vector<int> locs;
        for(int i = 0; i < n; i++){
            if(grid[i][j] =='L'){
                locs.push_back(i);
            }
        }
        if(locs.size() % 2){
            cout << "-1\n";
            return;
        }
        if(locs.size() == 0) continue;
        int half = locs.size() / 2;
        for(int k = 0; k < half; k++){
            grid[locs[k]][j] = 'W';
            grid[locs[k]][j + 1] = 'B';
        }
        for(int k = half; k < locs.size(); k++){
            grid[locs[k]][j] = 'B';
            grid[locs[k]][j + 1] = 'W';
        }
    }
    for(int i = 0; i < n; i++){
        vector<int> locs;
        for(int j = 0; j < m; j++){
            if(grid[i][j] =='U'){
                locs.push_back(j);
            }
        }
        if(locs.size() % 2){
            cout << "-1\n";
            return;
        }
        if(locs.size() == 0) continue;
        int half = locs.size() / 2;
        for(int k = 0; k < half; k++){
            grid[i][locs[k]] = 'W';
            grid[i + 1][locs[k]] = 'B';
        }
        for(int k = half; k < locs.size(); k++){
            grid[i][locs[k]] = 'B';
            grid[i + 1][locs[k]] = 'W';
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j] << (j == m - 1 ? "\n" : "");
        }
    }
}

int main() {
	int t; cin >> t;
    while(t--){
        solve();
    }
}
