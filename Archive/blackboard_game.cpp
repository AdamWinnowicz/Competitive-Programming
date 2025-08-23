#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    int zero_three = 0, one_two = 0;
    for(int i = 0; i < n; i++){
        int val = i % 4;
        if(val == 0 || val == 3) zero_three++;
        else one_two++;
    }
    cout << ((zero_three % 2 == 0 && one_two % 2 == 0) ? "Bob\n" : "Alice\n");
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