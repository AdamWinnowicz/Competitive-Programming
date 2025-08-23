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
    we have 2 arrays a and b

    we want the number of indices where ai > bi to be exactly x
*/
 

// Small Observations
/*
    if all the elements in ai are less than the smallest in bi, we can only have 0

    we probably should care about the largest elements of ai

    we can only rearrange the values of b

    the order of a doesn't really matter, so we can probably sort it

    a = 1 1 1 2 2 3 4 5 6 6

    if we have any elements in b that are smaller than the min of a, we know that their position doesn't matter and that it will be the lower bound on valid x

    if we have any elements in b that are larger than the max of a, we also know that their position doesn't matter

    now we have a set of elements which are in the range of min(a) to max(a), and we need to get a certain number of ai > bi

    this set of elements can be less than the number of elements in a

    
*/
 

// Claims on algo 
/*  
    we need to get x elements where ai > bi and n - x elements where ai <= bi

    put the n - x greatest elements of b under the n - x smallest elements of a

    if this does not create n - x elements where ai <= bi, it will be impossible anyways because we are using the best pairing possible to ensure ai <= bi (biggest b, smallest a)

    the ordering does not matter because we need all n - x elements in b to be larger than the maximum of the n - x smallest in a

    this greedily ensures that we get rid of the large numbers in b and the small numbers in a, making it easier to have all x elements in a be greater than elements of b

    afterwards we can just check whether the solution in good or not
*/

void test_case(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    vector<int> b(n);
    vector<pair<int,int>> c;
    for(int i = 0; i < n; i++){
        int z; cin >> z;
        a[i] = z;
        c.emplace_back(z, i);
    }
    for(int & z : b) cin >> z;
    sort(c.begin(), c.end());
    sort(b.begin(), b.end());
    vector<int> ansB(n);
    for(int i = x; i < n; i++){
        ansB[c[i-x].second] = b[i];
    }
    for(int i = 0; i < x; i++){
        ansB[c[i+n-x].second] = b[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > ansB[i]) cnt++;
    }
    if(cnt == x){
        cout << "YES\n";
        for(int i = 0; i < n; i++){
            cout << ansB[i] << (i == n - 1 ? "\n" : " ");
        }
    }
    else cout << "NO\n";
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