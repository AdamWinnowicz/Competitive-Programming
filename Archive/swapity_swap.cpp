#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    int n,k;
    cin >> n >> k;
    int a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;

    vector<int> p;
    for(int i = 1; i <=n; i++){
        int new_location = i;
        if(a1 <= new_location && new_location <= a2){
            new_location = a2 - (new_location - a1);
        }
        if(b1 <= new_location && new_location <= b2){
            new_location = b2 - (new_location - b1);
        }
        p.push_back(new_location);
    }
    vector<int> arrangement(n,0);
    for(int i = 1; i <=n; i++){
        int curr_location = i;
        int cycle_len = 0;
        while(true){
            curr_location = p[curr_location-1];
            cycle_len++;
            if(curr_location == i){
                break;
            }
        }
        int remaining_moves = k % cycle_len;
        for(int j = 0; j < remaining_moves; j++){
            curr_location = p[curr_location-1];
        }
        arrangement[curr_location-1] = i;
    }
    for(int val : arrangement){
        cout << val << '\n';
    }

    return 0;
}