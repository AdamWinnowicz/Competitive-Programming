#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        string num; cin >> num;
        int val = stoi(num);
        int root = sqrt(val);
        if(root*root == val){
            cout << 0 << " " << root << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }

    return 0;
}