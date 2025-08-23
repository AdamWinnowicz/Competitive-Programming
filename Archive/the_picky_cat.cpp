#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n; cin >> n;
        vector<int> arr;
        for(int i = 0; i < n; i++){
            int val; cin >> val;
            arr.push_back(abs(val));
        }
        int target = arr[0];
        int median_location = (n+1) / 2 - 1;
        sort(arr.begin(),arr.end());
        int new_ind = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] == target){
                new_ind = i;
                break;
            }
        }
        if((n % 2 == 0 && new_ind - 1 <= median_location) || new_ind <= median_location){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

    }

    return 0;
}