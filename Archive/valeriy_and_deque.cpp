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
    given an list of n elements

    make operations considering the first two elements, where you always move the smaller one to the end of the list

    for each query m, determine the first two elements before the mth operation
*/
 

// Small Observations
/*
    let's look at examples

    1:  1 2 3 4 5 
    2:  2 3 4 5 1
    3:  3 4 5 1 2
    4:  4 5 1 2 3
    5:  5 1 2 3 4
    6:  5 2 3 4 1
    7:  5 3 4 1 2
    8:  5 4 1 2 3
    9:  5 1 2 3 4
    10: 5 2 3 4 1

    first, we need to find the location of the maximum. 

    if the location is i, the max will be at the front in i - 1 moves

    we can simulate these moves because i is less than n and n is small enough

    if any of the queries are within this range, we can answer them immediately

    otherwise there is a cycle, where every element is arranged in the same way that it is originally and it just loops through bringing the elements to the end

    in order to find this value quickly, we can save the positions of the list values and then take moves modulo n - 1

    then with the remaining moves we know that the value at index 2 will be the one which is currently at position rem + 1 or rem (0 indexed)
*/
 

// Claims on algo 
/*  
    
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    deque<int> a(n);
    int mx = -1, mx_loc = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > mx){
            mx = a[i];
            mx_loc = i;
        }
    }
    vector<pair<int,int>> first_two(mx_loc + 1);
    int op = 1;
    while(a[0] != mx){
        int A = a[0], B = a[1];
        first_two[op] = {A, B}; 
        a.pop_front(); a.pop_front();
        if(A <= B){
            a.push_front(B);
            a.push_back(A);
        }
        else{
            a.push_front(A);
            a.push_back(B);
        }
        op++;
    }
    for(int i = 0; i < q; i++){
        ll m; cin >> m;
        if(m <= mx_loc){
            cout << first_two[m].first << " " << first_two[m].second << '\n';
        }
        else{
            m -= (mx_loc + 1);
            m %= (n - 1);
            int second_element = a[m + 1];
            cout << mx << " " << second_element << '\n';
        }
    }

    return 0;
}