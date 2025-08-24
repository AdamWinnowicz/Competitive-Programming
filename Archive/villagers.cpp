#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

// Problem Statement
/*
    we have an array

    we can select two elements of the array

    it costs max of the two elements we select to decrease their values both by the minimum of the two values (the smaller one becomes 0, the other one becomes the difference)

    you want all values to be connected by path of selections
*/
 

// Small Observations
/*
    we can connect all the values through paths by choosing one value to start at and pairing it with every other value

    this only requires n - 1 selections

    however, this doesn't seem to be that helpful

    once we connect two elements, we need to connect an unconnected element to one that is already connected

    we can connect any elements for a cost of their max

    each element must be connected at some point

    and we will always have to use the maximum at some point before it has been decreased, which will lower both its value and the value that it pairs with for the cost of its value

    once you have a zero, you can pair it with every other element for a cost of each of those elements

    so we can always remove the second largest element and not have to use it

    once we choose two elements, we always get a zero

    then we can connect those groups by connecting the zero for no cost

    in this way, we always want to pair the largest with the next largest to minimize the cost

    so the answer is just the alternating elements 


*/
 

// Claims on algo 
/*  
    
*/

void test_case(){
    int n; cin >> n;
    vector<int> g(n);
    for(int & x : g) cin >> x;
    sort(g.begin(), g.end());
    ll ans = 0;
    for(int i = n - 1; i > -1; i-=2){
        ans += g[i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}