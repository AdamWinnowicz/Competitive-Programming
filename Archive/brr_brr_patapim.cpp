#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(2*n+1);
        set<int> possible;
        for(int i = 1; i < 2*n+1; i++) possible.insert(i);
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < n+1; j++){
                cin >> a[i+j-1];
                possible.erase(a[i+j-1]);
            }
        }
        cout << *possible.begin();
        for(int i = 1; i < 2*n; i++){
            cout << " " << a[i];
        }
        cout << '\n';
    }

    return 0;
}