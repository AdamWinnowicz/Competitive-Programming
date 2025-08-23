#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll a, b; cin >> a >> b;
    ll count_up = 0, cur = 1;
    vector<ll> an, bn;
    while(count_up < max(a, b)){
        count_up += cur;
        cur++;
    } 
    ll extra = count_up - max(a, b);
    if(a < b){
        if(a >= extra && extra != 0){
            an.push_back(extra);
        }
        for(int i = 1; i < cur; i++){
            if(i != extra) bn.push_back(i);
        }
        count_up = extra + cur;
        while(count_up <= a){
            an.push_back(cur);
            cur++;
            count_up += cur;
        }
    }
    else{
        if(b >= extra && extra != 0){
            bn.push_back(extra);
        }
        for(int i = 1; i < cur; i++){
            if(i != extra) an.push_back(i);
        }
        count_up = extra + cur;
        while(count_up <= b){
            bn.push_back(cur);
            cur++;
            count_up += cur;
        }
    }
    cout << an.size() << '\n';
    for(int i = 0; i < (int) an.size(); i++){
        cout << an[i] << (i == (int) an.size() - 1 ? '\n' : ' ');
    }
    cout << bn.size() << '\n';
    for(int i = 0; i < (int) bn.size(); i++){
        cout << bn[i] << (i == (int) bn.size() - 1 ? '\n' : ' ');
    }
}

int main() {
	solve();
}
