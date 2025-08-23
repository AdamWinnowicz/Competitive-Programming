#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    map<int, int> count;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        a[i] = val % k;
        count[a[i]]++;
    }
    bool found = false;
    for(int i = 0; i < n; i++){
        if(count[a[i]] == 1){
            cout << "YES\n";
            cout << i+1 << '\n';
            found = true;
            break;
        }
    }
    if(!found){
        cout << "NO\n";
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