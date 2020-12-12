#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int expIndex(int hay[], int start, bool left, int N){
    int last = start;
    int r = 1;
    int size = N;
    int dir;
    
    if (left)
        dir = -1;
    else
        dir = 1;
    if (left){
        while (last > 0 && last - 1 < size - 1){
            int next = last;
            while ((next + dir >= 0 && next + dir < size) && abs(hay[next + dir] - hay[last]) <= r){
                next += dir;
          }
            if (next == last)
                break;
            last = next;
            r++;
        }
    }
    else {
        while (last + 1 > 0 && last < size - 1){
            int next = last;
            while ((next + dir >= 0 && next + dir < size) && abs(hay[next + dir] - hay[last]) <= r){
                next += dir;
            }
            if (next == last)
                break;
            last = next;
            r++;
        }
    }
    return last;
}


int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    
    int N = 0;
    int ans = 0;
    cin >> N;

    int hay[100];
    for(int i = 0; i < N; i++){
        cin >> hay[i];
    }
    sort(hay, hay + N);

    ans = 1;
    for (int i = 0; i < N; i++){
        int left = expIndex(hay, i, true, N);
        int right = expIndex(hay, i, false, N);
        int explode = right - left + 1;
        if (explode > ans){
            ans = explode;
        }
    }
    
    cout << ans << endl;
    return 0;
}

