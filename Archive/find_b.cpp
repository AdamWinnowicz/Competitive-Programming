// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*

    we are given an array

    we are given q queries on subarrays

    determine whether there exists another integer array 

    such that all elements are different from the original

    the sum is the same

    and all elements are at least one

    if all the elements are greater than one, just move one from each value to an arbitrary place and sum will be the same but all will be different

    otherwise, we have to make all the ones into twos first

    this means that we need the sum of the other elements minus the number of other elements to be at least the number of ones

    sum_other = total_sum - num_ones

    num_other = length - num_ones

    sum_other - num_other = total_sum - length

    total_sum - length must be >= num_ones

    keep track of sums and num_ones with prefix sum precomputation


*/

void solve(){
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> prefsum(n + 1), prefones(n + 1);
    prefsum[0] = prefones[0] = 0;
    for(int i = 1; i <= n; i++){
        prefsum[i] = prefsum[i-1] + a[i-1];
        prefones[i] = prefones[i-1] + (a[i-1] == 1);
    }
    for(int i = 0; i < q; i++){
        ll l, r; cin >> l >> r; l--; r--;
        ll total_sum = prefsum[r+1] - prefsum[l];
        //cout << r << " " << prefsum[r+1] << '\n';
        ll ones = prefones[r+1] - prefones[l];
        ll length = r - l + 1;
        //cout << total_sum << " " <<  length << " " << ones << '\n';
        if(l != r && total_sum - length >= ones){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }

}
int main() {
	int t; cin >> t;
    while(t--){
        solve();
    }
}
