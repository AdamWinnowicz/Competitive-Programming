#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> operations(1e5 + 5, 0);

void test_case(){
    int n; cin >> n;
    cout << operations[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll c = 1, ops = 1;
    for(int i = 1; i <= 1e5; i++){
        operations[i] = ops;
        if(i == c){
            c = (c+1) * 2;
            ops++;
        }
    }

    int t; cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}