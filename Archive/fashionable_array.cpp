#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(),a.end());
        int nearest_even_left = -1, nearest_odd_left = -1;
        for(int i = 0; i < n; i++){
            if(a[i] % 2 == 0 && nearest_even_left == -1){
                nearest_even_left = i;
            }
            if(a[i] % 2 == 1 && nearest_odd_left == -1){
                nearest_odd_left = i;
            }
        }
        int nearest_even_right = -1, nearest_odd_right = -1;
        for(int i = n-1; i > -1; i--){
            if(a[i] % 2 == 0 && nearest_even_right == -1){
                nearest_even_right = n - i - 1;
            }
            if(a[i] % 2 == 1 && nearest_odd_right == -1){
                nearest_odd_right = n - i - 1;
            }
        }
        int operations = -1;
        if(nearest_even_left != -1 && nearest_even_right != -1){
            operations = nearest_even_left + nearest_even_right;
        }
        if(operations == -1){
            operations = nearest_odd_left + nearest_odd_right;
        }
        else if (nearest_odd_left != -1 && nearest_odd_right != -1){
            operations = min(operations, nearest_odd_left + nearest_odd_right);
        }
        cout << operations << '\n';

    }

    return 0;
}