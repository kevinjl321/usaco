#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    ll x, y;
    cin >> x >> y;

    ll ans = 0;
    ll by = 1;
    ll dir = 1;

    while(true) {
        if((dir==1 && x<=y && y<=x+by) || (dir==-1 && x-by<=y && y<=x)) {
            ans += abs(y-x);
            cout << ans << endl;
            break;
        } 
        else {
            ans += by*2;
            by *= 2;
            dir *= -1;
        }
    }
    
    return 0;
}