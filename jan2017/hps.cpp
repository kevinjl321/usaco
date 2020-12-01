#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;

int hps(int h, int p, int s){
    int count = 0;
    for(int i = 0; i < n ; i++){
        if(v[i].first == h && v[i].second == s) count++;
        if(v[i].first == p && v[i].second == h) count++;
        if(v[i].first == s && v[i].second == p) count++;
    }
    return count;
}

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    cin >> n;

    for(int i = 0; i < n; i++){
        int f, s;
        cin >> f >> s;
        v.emplace_back(f, s);
    }

    int scores[7];
    scores[0] = hps(1, 2, 3);
    scores[1] = hps(1, 3, 2);
    scores[2] = hps(2, 1, 3);
    scores[3] = hps(2, 3, 1);
    scores[4] = hps(3, 1, 2);
    scores[5] = hps(3, 2, 1);

    int ans = -1;
    for(int i = 0; i < 6; i++){
        if(scores[i] > ans){
            ans = scores[i];
        }
    }

    cout << ans << endl;
    return 0;
}