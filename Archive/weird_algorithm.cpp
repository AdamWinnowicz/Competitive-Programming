#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    while(!(n==1)){
        cout << n << " ";
        if(n % 2 == 0){
            n /= 2;
        }
        else{
            n *= 3;
            n ++;
        }
    }
    cout << 1;

    return 0;
}