#include <bits/stdc++.h>
using namespace std;

struct Rect{
    int x1,y1,x2,y2;
};

bool intersect(Rect a, Rect b){
    int x_intersect = min(a.x2,b.x2) - max(a.x1,b.x1);
    int y_intersect = min(a.y2,b.y2) - max(a.y1,b.y1);
    return x_intersect >= 0 && y_intersect >= 0;
}

bool in_rect(int x, int y , Rect a){
    return a.x1 <= x && x <= a.x2 && a.y1 <= y && y <= a.y2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // simple solution: check is the two black rectangles intersect and all 4 corners of the white rectangle are covered
    Rect w, b1, b2;
    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2 >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2 >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    if((in_rect(w.x1,w.y1,b1) && in_rect(w.x2,w.y1,b1) && in_rect(w.x1,w.y2,b1) && in_rect(w.x2,w.y2,b1)) || (in_rect(w.x1,w.y1,b2) && in_rect(w.x2,w.y1,b2) && in_rect(w.x1,w.y2,b2) && in_rect(w.x2,w.y2,b2))){
        cout << "NO\n";
    }
    else if(intersect(b1,b2) && (in_rect(w.x1,w.y1,b1) || in_rect(w.x1,w.y1,b2)) && (in_rect(w.x2,w.y1,b1) || in_rect(w.x2,w.y1,b2)) && (in_rect(w.x1,w.y2,b1) || in_rect(w.x1,w.y2,b2)) && (in_rect(w.x2,w.y2,b1) || in_rect(w.x2,w.y2,b2))){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
    }
    return 0;
}