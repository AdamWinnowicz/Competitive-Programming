#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int one_count = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') one_count++;
    }
    if(one_count <= k) cout << "Alice\n";
    else{
        cout << (k > n / 2 ? "Alice\n" : "Bob\n");
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