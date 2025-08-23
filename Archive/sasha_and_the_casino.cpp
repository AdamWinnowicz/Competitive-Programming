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
    You have A coins

    If you make a bet of y coins and succeed, you will gain (k - 1) * y coins

    If you fail, you will lose y coins

    You can have a maximum of x consecutive losses

    Is it possible to get whatever number of coins you want and then stop betting

    HUGE PROBLEM WITH MY UNDERSTANDING 

    He only needs to be able to reach at least n coins, meaning that any number of coins less than the initial are already guaranteed
    
*/
 

// Small Observations
/*
    If we ever reach 0 coins, we cannot keep betting

    Guaranteeing the ability to get any possible number of coins seems like a pretty overkill ability

    Something is important about the rule that you can never lose x games in a row

    This means that every x games you are guaranteed to win, allowing you to gain coins by any multiple of (k - 1)

    Because we need to guarantee everything, we can probably change this problem to be that we will lose when it matters most

    
*/
 

// Claims on algo 
/*  
    If we have less coins or equal to the max number of losses in a row, we cannot guarantee any number because we could lose every game (bets are at least 1)

    if a <= x ---> NO

    Now that we have more than x coins, we can bet one coin for the first x times and still have a - x coins left in the worst case scenario

    these a - x coins can be bet and we will get (a - x) * (k - 1) more coins

    If the number of new coins we get is greater than the number of coins we lost (at worst x) we can guarantee every number
    
    Test case k = 3, x = 3, a = 6
    we can bet 1 for the first three
    if we lose all three times, we will have a = 3 and then we can bet everything to reach 3 * 3 = 9 coins, then the process repeats

    what if we lose the first two times, then win the third?
    We lose 2 and become a = 4, and then bet only 1 for the third to win 2 * 1 coins, which will return us to 6 and we will not be able to win more

    This means that simply betting one coin greedily and then guessing the right time is not always guaranteed

    We can guarantee stuff by betting the same number of coins every time, because we will be able to get num * (k - 1) coins guaranteed every x bets (worst case scenario)

    If we always choose one, k - 1 must be greater than x which is sometimes the case

    If we always choose two, 2 * (k - 1) must be greater than 2 * x, which is the same expression as before

    If we always choose three, 3 * (k - 1) must be greater than 3 * x, also the same expression
    ...
    therefore we can win if k - 1 > x

    What about responding to losses?

    If we just lost z times, we can bet the same number of coins c for the next x - z + 1 times and guarantee c * (k - 1) coins

    That costs us a total of (x - z + 1) * c + z

    So if ((x - z + 1) * c + z) < c * (k - 1) we will be able to win

    We can always loop over the number of losses becuase it is <= k 

    New idea

    We need to account for the fact that we are guaranteed to win within the first x + 1 moves

    This means that we need to guarantee a victory no matter when our first win occurs

    We need a specific set of moves s.t we will gain coins no matter when we first win

    As soon as we win our first game, we can reset this cycle with even more coins and continue to increase coins forever

    This is because betting in this specific way guarantees that we will gain more coins than we lost in order to get there 

    Without betting at least the number of coins necessary in this method, we will be unable to account for winning on specific days and will not be able to guarantee a win

    Greedily we choose the smallest numbers such that we can still facilitate a gain, as once this gain happens we can do it an infinite number of times and win, but choosing more coins earlier might cause us to not have enough later, so lets just choose the smallest amount necessary to win

    At a current bet, choose the smallest number j which is greater than the amount we already spent when multiplied by (k - 1)

    j * (k - 1) > already_spent
    j > already_spent / (k - 1)
*/

bool test_case(){
    ll k, x, a; cin >> k >> x >> a;
    if(a <= x){
        return false;
    }
    if(k - 1 > x){
        return true;
    }
    ll already_spent = 0;
    for(int i = 0; i < x + 1; i++){
        ll l = 0, r = 1e18;
        while(l < r){
            ll j = l + (r - l) / 2;
            if(j > already_spent / (k - 1)){
                r = j;
            }
            else{
                l = j + 1;
            }
        }
        already_spent += l;
        if(already_spent > a) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}