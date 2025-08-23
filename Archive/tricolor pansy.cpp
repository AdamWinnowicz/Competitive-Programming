#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int a,b,c,d; cin >> a >> b >> c >> d;
        int gelly = min(a,c);
        int flow = min(b,d);
        if(gelly < flow){
            cout << "Flower\n";
        }
        else{
            cout << "Gellyfish\n";
        }
    }

    return 0;
}