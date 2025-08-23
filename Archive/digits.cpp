#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n, d; cin >> n >> d;
    vector<int> digits = {1, 3, 5, 7, 9};
    set<int> divides = {1};
    for(int digit : digits){
        if(d % digit == 0 && digit <= d){
            divides.insert(digit);
        }
    }
    if(n >= 3){
        divides.insert(3); divides.insert(7);
        if(d == 3 || d == 6) divides.insert(9);
    }
    if(n >= 6){
        divides.insert(9);
    }
    vector<int> div;
    for(int digit : divides) div.push_back(digit);
    for(int i = 0; i < div.size(); i++){
        cout << div[i] << (i == div.size()-1 ? "\n" : " ");
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