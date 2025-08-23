// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*

    undirected graph with n vertices, which can be disconnected

    no loops or multiple edges

    when at a current node, you can go to any node value you want

    however, if you just went up to a higher node value, you cannot go up to a higher node value again

    find the maximum number of edges you can place between all the nodes

    obs: bc symmetrical, you also cannot go down twice in a row

    this means that the pattern always has to be alternating (up down up down up etc.)

    what is the upper bound on edges?

    if you could make every pair, there would be n * (n - 1) / 2 edges

    this does not have double edges of self edges, so it fits the constraint

    at a current node value, all the nodes it is connected to must either be greater or less than the current value

    however, because the graph can be disconnected we can guarantee one edge between every two nodes

    so we have a lower bound of n / 2 edges

    what can we do to make these components better?

    the check only considers 3 nodes at a time, which have to be connected by two edges

    this means that it only affects nodes at a distance of 2, which you can verify by only looking at adjacent edges

    the key is, any one node is adjacent to either all greater or all lesser

    one thing that we can do is that we can sort the nodes

    we can connect the bigger node to all the nodes it is smaller than
    
    then we can do that for every other bigger node to those nodes

    we can take a set of nodes

    and for all the values which are strictly smaller or strictly larger, we can connect them to every one of that set

    this is because they are guaranteed to be greater than all elements, and all other elements that might connect are also greater so we get up down up for every path

    we can iterate over this by sorting

    for every index, we can consider the prefix as a potential subset of smaller elements

    as soon as we get a new value not equal to the previous, we consider the number of elements in the prefix times the number in the suffix

    we can do the same in the other direction to consider suffixes
*/
void solve(){
    ll n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = n / 2;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i-1]){
            ll product = i * (n - i);
            ans = max(ans, product);
        }
    }
    for(int i = n - 2; i > -1; i--){
        if(a[i] != a[i+1]){
            ll product = (i + 1) * (n - i - 1);
            ans = max(ans, product);
        }
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while(t--){
        solve();
    }
}
