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
    
*/
 

// Small Observations
/*
    The input is similar to an adjacency matrix - how can this be represented as a graph?

    nodes with smaller degree can be smaller sets

    when there is a large degree, you need to have at least the degree number of distinct elements in the set

    proper subset means that we have to add an extra element when we use a previous set to construct the next one



*/
 

// Claims on algo 
/*  
    lets say that a set is a subset of another. there is now a directed edge between set i and set j

    at a current node, lets take all the edges that are directed into it and take all the elements from them

    if the set is distinct, we can just move on 

    otherwise we add a new element to the set which we iterate over with a pointer

    sort sets by their degrees and set the leaves with degree of zero (they must exist) to elements by using the pointer

    for each of the nodes with degree 0, push the value it has to all of the edges it meets and add them to the queue

    problem: how do we avoid equal subsets?

    because n is so small and we only have n subsets, just check if the current subset is unique in o(n), and then add the next element that the pointer is on if it is necessary
    
*/

void test_case(){
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n; i++){
        string z; cin >> z;
        for(int j = 0; j < n; j++){
            if(z[j] == '1'){
                adj[i].push_back(j + 1);
            }
        }
    }

    vector<set<int>> sets(n + 1);
    for(int i = 1; i <= n; i++) sets[i].insert(i);
    
    for(int i = 1; i <= n; i++){
        for(int v : adj[i]){
            sets[v].insert(sets[i].begin(), sets[i].end());
        }
    }

    for(int i = 1; i <= n; i++){
        set<int> s = sets[i];
        cout << s.size();
        for(int v : s){
            cout << " " << v;
        }
        cout << '\n';
    }

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