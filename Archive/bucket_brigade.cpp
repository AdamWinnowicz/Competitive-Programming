#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    pair<int,int> barn, rock, lake;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            char loc;
            cin >> loc;
            if(loc == 'B'){
                barn = make_pair(i,j);
            }
            if(loc == 'R'){
                rock = make_pair(i,j);
            }
            if(loc == 'L'){
                lake = make_pair(i,j);
            }
        }
    }
    int distance = 0;
    if((lake.first == barn.first && lake.first == rock.first && (lake.second < rock.second && rock.second < barn.second || barn.second < rock.second && rock.second < lake.second)) 
    || (lake.second == barn.second && lake.second == rock.second && (lake.first < rock.first && rock.first < barn.first || barn.first < rock.first && rock.first < lake.first))){
        distance += 2;
    }
    distance += abs(lake.first - barn.first) + abs(lake.second - barn.second) - 1;

    cout << distance << '\n';
    return 0;
}