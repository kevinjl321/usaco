#include <iostream>
using namespace std;
 
int solve(int dist) {
    int minspeed;
    cin >> minspeed;

    int lhstravel = 0;
    int rhstravel = 0;
    int timeused = 0;
    for(int currspeed = 1; ; currspeed++) {
        lhstravel += currspeed;
        timeused++;
        if(lhstravel + rhstravel >= dist){
            return timeused;
        }
        if(currspeed >= minspeed) {
            rhstravel += currspeed;
            timeused++;
            if(lhstravel + rhstravel >= dist){
                return timeused;
            }
        }
    }
}
 
int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    int k, n;
    cin >> k >> n;

    for(int i = 0; i < n; i++) {
        cout << solve(k) << endl;
    }
}

