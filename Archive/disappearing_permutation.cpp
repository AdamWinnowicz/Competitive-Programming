#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<int> a(n), d(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> d[i];
    set<int> fixed;
    for(int i = 0; i < n; i++){
        int removed = a[d[i] - 1];
        if(fixed.find(removed) == fixed.end()){
            fixed.insert(removed);
            int curr = a[removed-1];
            while(curr != removed){
                fixed.insert(curr);
                curr = a[curr-1];
            }
        }
        cout << fixed.size() << (i == n-1 ? "\n" : " ");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}