#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n; 
    cin >> n;

    int time = 0;
    pair<int, int> a[101];
    for (auto &x: a) {
        cin >> x.first >> x.second;
    }
    sort(a, a + n);

    for (auto &x: a) {
        if (time >= x.first) {
            time += x.second;
        } else {
            time += x.first - time;
            time += x.second;
        }
    }
    
    cout << time << endl;
    return 0;
}